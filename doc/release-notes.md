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
your wallet has all the new data synced (only if you were using version < 0.12.3).

When spork15 will be activated on mainnet, there is no need for `masternode start`
anymore. Upgrading a masternode now only involves replacing binaries and restarting
the node.

Downgrade warning
-----------------

### Downgrade to a version < 0.12.3.1

Downgrading to previous 0.12.2 releases is fully supported but is not recommended unless you have some serious issues with 0.12.3.1.

Notable changes
===============

Number of false-positives from anti virus software should be reduced
--------------------------------------------------------------------
We have removed all mining code from Windows and Mac binaries, which should avoid most of the false-positive alerts
from anti virus software. Linux builds are not affected. The mining code found in `absolute-qt` and `absoluted` are only meant
for regression/integration tests and povnets, so there is no harm in removing this code from non-linux builds.

Fixed an issue with invalid merkle blocks causing SPV nodes to ban other nodes
------------------------------------------------------------------------------
A fix that was introduces in the last minor version caused creation of invalid merkle blocks, which in turn cause SPV
nodes to ban 0.12.3 nodes. This can be observed on mobile clients which have troubles maintaining connections. This
release fixes this issue and should allow SPV/mobile clients to sync with upgraded nodes.


Bug fixes/Other improvements
----------------------------
There are few bug fixes in this release:
- Fixed an issue with transaction sometimes not being fully zapped when `-zapwallettxes` is used
- Fixed an issue with the `protx revoke` RPC and REASON_CHANGE_OF_KEYS


How to Upgrade
--------------

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over /Applications/absolute-Qt (on Mac) or
absoluted/absolute-qt (on Linux).

Downgrade warning
-----------------

### Downgrade to a version < 0.12.3.1

Downgrading to a version smaller than 0.12.3.1 is only supported as long as DIP2/DIP3
has not been activated. Activation will happen when enough miners signal compatibility
through a BIP9 (bit 3) deployment.


byaccount`, `listaccounts`.

### Downgrade to 0.12.2.5

Downgrading to 0.12.2.2 does not require any additional actions, should be
fully compatible.

Notable changes
===============

Initial release.
