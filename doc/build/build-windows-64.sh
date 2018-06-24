#! /bin/sh

cd ..
cd .. 

PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g') # strip out problematic Windows %PATH% imported var
cd depends
chmod 764  ./config.guess
chmod 764  ./config.sub
make HOST=x86_64-w64-mingw32
cd ..
chmod +x autogen.sh
./autogen.sh # not required when building from tarball
CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --prefix=/
sudo chmod 764  share/genbuild.sh
make