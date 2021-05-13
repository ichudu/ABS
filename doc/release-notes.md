Absolute Core version 0.12.2.5
==========================

Release is now available from:

  <hhttps://github.com/absolute-community/absolute/releases>

Please report bugs using the issue tracker at github:

  <https://github.com/absolute-community/absolute/issues>


How to Upgrade
--------------

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over /Applications/Absolute-Qt (on Mac) or
absoluted/absolute-qt (on Linux). If you upgrade after DIP0003 activation you will
have to reindex (start with -reindex-chainstate or -reindex) to make sure
your wallet has all the new data synced (only if you were using version < 0.13).

As spork15 has been activated on mainnet, there is no need for `masternode start`
anymore. Upgrading a masternode now only involves replacing binaries and restarting
the node.

Downgrade warning
-----------------

### Downgrade to a major version < 0.13.0.0

Downgrading to a major version smaller than 0.13 is not supported anymore as DIP2/DIP3 has activated
on mainnet and testnet.

### Downgrade to a minor version < 0.13.0.1

Downgrading to previous 0.13 releases is fully supported but is not recommended unless you have some serious issues with the latest minor version

Notable changes
===============

Number of false-positives from anti virus software should be reduced
--------------------------------------------------------------------
We have removed all mining code from Windows and Mac binaries, which should avoid most of the false-positive alerts
from anti virus software. Linux builds are not affected. The mining code found in `absolute-qt` and `absoluted` are only meant
for regression/integration tests and devnets, so there is no harm in removing this code from non-linux builds.

Fixed an issue with invalid merkle blocks causing SPV nodes to ban other nodes
------------------------------------------------------------------------------


Hardened spork15 value to 970000
---------------------------------
We've hardened the spork15 block height to 970000, which makes sure that syncing from scratch will always work, no
matter if spork15 is received in-time or not.

Bug fixes/Other improvements
----------------------------
There are few bug fixes in this release:
- Fixed an issue with transaction sometimes not being fully zapped when `-zapwallettxes` is used
- Fixed an issue with the `protx revoke` RPC and REASON_CHANGE_OF_KEYS

 0.13.0.1 Change log
===================

See detailed [set of changes](https://github.com/absolute-community/absolute/compare/v12.3.1...absolute:v13.0.1).

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over /Applications/absolute-Qt (on Mac) or
absoluted/absolute-qt (on Linux).






byaccount`, `listaccounts`.






