Absolute Core version 0.12.2.5
==========================

Release is now available from:

  <hhttps://github.com/absolute-community/absolute/releases>

Please report bugs using the issue tracker at github:

  <https://github.com/absolute-community/absolute/issues>


Upgrading and downgrading
=========================

How to Upgrade
--------------

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over /Applications/absolute-Qt (on Mac) or
absoluted/absolute-qt (on Linux).

Downgrade warning
-----------------

### Downgrade to a version < 0.12.2.2

Because release 0.12.2.5 included the [per-UTXO fix]
which changed the structure of the internal database, you will have to reindex
the database if you decide to use any pre-0.12.2.2 version.

Wallet forward or backward compatibility was not affected.

### Downgrade to 0.12.2.2

Downgrading to 0.12.2.2 does not require any additional actions, should be
fully compatible.

Notable changes
===============

Initial release.
