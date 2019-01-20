Release Process
====================

* Update translations, see [translation_process.md](https://github.com/absolute-community/absolute/blob/master/doc/translation_process.md#synchronising-translations).
* Update hardcoded [seeds](/contrib/seeds)

* * *

### First time / New builders
Check out the source code in the following directory hierarchy.

	cd /path/to/your/toplevel/build
	git clone https://github.com/absolute-community/gitian.signatures.git
	git clone https://github.com/absolute-community/absolute.detached.signatures.git
	git clone https://github.com/devrandom/gitian-builder.git
	git clone https://github.com/absolute-community/absolute.git

###Absolute Core maintainers/release engineers, update (commit) version in sources

	pushd ./absolute
	contrib/verifysfbinaries/verify.sh
	configure.ac
	doc/README*
	doc/Doxyfile
	contrib/gitian-descriptors/*.yml
	src/clientversion.h (change CLIENT_VERSION_IS_RELEASE to true)

	# tag version in git

	git tag -s v(new version, e.g. 0.8.0)

	# write release notes. git shortlog helps a lot, for example:

	git shortlog --no-merges v(current version, e.g. 0.7.2)..v(new version, e.g. 0.8.0)
	popd

* * *

### Setup and perform Gitian builds

 Setup Gitian descriptors:

	pushd ./absolute
	export SIGNER=(your Gitian key, ie bluematt, sipa, etc)
	export VERSION=(new version, e.g. 0.8.0)
	git fetch
	git checkout v${VERSION}
	popd

  Ensure your gitian.signatures are up-to-date if you wish to gverify your builds against other Gitian signatures.

	pushd ./gitian.signatures
	git pull
	popd

  Ensure gitian-builder is up-to-date:

	pushd ./gitian-builder
	git pull

### Fetch and create inputs: (first time, or when dependency versions change)

	mkdir -p inputs
	wget -P inputs https://bitcoincore.org/cfields/osslsigncode-Backports-to-1.7.1.patch
	wget -P inputs http://downloads.sourceforge.net/project/osslsigncode/osslsigncode/osslsigncode-1.7.1.tar.gz

  Create the OS X SDK tarball, see the [OS X readme](README_osx.md) for details, and copy it into the inputs directory.

### Optional: Seed the Gitian sources cache and offline git repositories

By default, Gitian will fetch source files as needed. To cache them ahead of time:

	make -C ../absolute/depends download SOURCES_PATH=`pwd`/cache/common

Only missing files will be fetched, so this is safe to re-run for each build.

NOTE: Offline builds must use the --url flag to ensure Gitian fetches only from local URLs. For example:
```
./bin/gbuild --url absolute=/path/to/absolute,signature=/path/to/signatures {rest of arguments}
```
The gbuild invocations below <b>DO NOT DO THIS</b> by default.

### Build and sign Absolute Core for Linux, Windows, and OS X:

	./bin/gbuild --commit absolute=v${VERSION} ../absolute/contrib/gitian-descriptors/gitian-linux.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-linux --destination ../gitian.signatures/ ../absolute/contrib/gitian-descriptors/gitian-linux.yml
	mv build/out/absolute-*.tar.gz build/out/src/absolute-*.tar.gz ../

	./bin/gbuild --commit absolute=v${VERSION} ../absolute/contrib/gitian-descriptors/gitian-win.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-win-unsigned --destination ../gitian.signatures/ ../absolute/contrib/gitian-descriptors/gitian-win.yml
	mv build/out/absolute-*-win-unsigned.tar.gz inputs/absolute-win-unsigned.tar.gz
	mv build/out/absolute-*.zip build/out/absolute-*.exe ../

	./bin/gbuild --commit absolute=v${VERSION} ../absolute/contrib/gitian-descriptors/gitian-osx.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-osx-unsigned --destination ../gitian.signatures/ ../absolute/contrib/gitian-descriptors/gitian-osx.yml
	mv build/out/absolute-*-osx-unsigned.tar.gz inputs/absolute-osx-unsigned.tar.gz
	mv build/out/absolute-*.tar.gz build/out/absolute-*.dmg ../
	popd

  Build output expected:

  1. source tarball (absolute-${VERSION}.tar.gz)
  2. linux 32-bit and 64-bit dist tarballs (absolute-${VERSION}-linux[32|64].tar.gz)
  3. windows 32-bit and 64-bit unsigned installers and dist zips (absolute-${VERSION}-win[32|64]-setup-unsigned.exe, absolute-${VERSION}-win[32|64].zip)
  4. OS X unsigned installer and dist tarball (absolute-${VERSION}-osx-unsigned.dmg, absolute-${VERSION}-osx64.tar.gz)
  5. Gitian signatures (in gitian.signatures/${VERSION}-<linux|{win,osx}-unsigned>/(your Gitian key)/

### Verify other gitian builders signatures to your own. (Optional)

  Add other gitian builders keys to your gpg keyring

	gpg --import ../absolute/contrib/gitian-keys/*.pgp

  Verify the signatures

	./bin/gverify -v -d ../gitian.signatures/ -r ${VERSION}-linux ../absolute/contrib/gitian-descriptors/gitian-linux.yml
	./bin/gverify -v -d ../gitian.signatures/ -r ${VERSION}-win-unsigned ../absolute/contrib/gitian-descriptors/gitian-win.yml
	./bin/gverify -v -d ../gitian.signatures/ -r ${VERSION}-osx-unsigned ../absolute/contrib/gitian-descriptors/gitian-osx.yml

	popd

### Next steps:

Commit your signature to gitian.signatures:

	pushd gitian.signatures
	git add ${VERSION}-linux/${SIGNER}
	git add ${VERSION}-win-unsigned/${SIGNER}
	git add ${VERSION}-osx-unsigned/${SIGNER}
	git commit -a
	git push  # Assuming you can push to the gitian.signature tree
	popd

  Wait for Windows/OS X detached signatures:
	Once the Windows/OS X builds each have 3 matching signatures, they will be signed with their respective release keys.
	Detached signatures will then be committed to the [absolute-detached-signatues](https://github.com/absolute-community/absolute-detached-signaturess) repository, which can be combined with the unsigned apps to create signed binaries.

  Create (and optionally verify) the signed OS X binary:

	pushd ./gitian-builder
	./bin/gbuild -i --commit signature=v${VERSION} ../absolute/contrib/gitian-descriptors/gitian-osx-signer.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-osx-signed --destination ../gitian.signatures/ ../absolute/contrib/gitian-descriptors/gitian-osx-signer.yml
	./bin/gverify -v -d ../gitian.signatures/ -r ${VERSION}-osx-signed ../absolute/contrib/gitian-descriptors/gitian-osx-signer.yml
	mv build/out/absolute-osx-signed.dmg ../absolute-${VERSION}-osx.dmg
	popd

  Create (and optionally verify) the signed Windows binaries:

	pushd ./gitian-builder
	./bin/gbuild -i --commit signature=v${VERSION} ../absolute/contrib/gitian-descriptors/gitian-win-signer.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-win-signed --destination ../gitian.signatures/ ../absolute/contrib/gitian-descriptors/gitian-win-signer.yml
	./bin/gverify -v -d ../gitian.signatures/ -r ${VERSION}-win-signed ../absolute/contrib/gitian-descriptors/gitian-win-signer.yml
	mv build/out/absolute-*win64-setup.exe ../absolute-${VERSION}-win64-setup.exe
	mv build/out/absolute-*win32-setup.exe ../absolute-${VERSION}-win32-setup.exe
	popd

Commit your signature for the signed OS X/Windows binaries:

	pushd gitian.signatures
	git add ${VERSION}-osx-signed/${SIGNER}
	git add ${VERSION}-win-signed/${SIGNER}
	git commit -a
	git push  # Assuming you can push to the gitian.signatures tree
	popd
