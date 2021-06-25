Absolute Core version 0.14.0.1
==========================

Release is now available from:

  <https://absify.me/wallets/>

Please report bugs using the issue tracker at github:

  <https://github.com/absolute-community/absolute/issues>


How to Upgrade
--------------

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over /Applications/Absolute-Qt (on Mac) or
dabsoluted/absolute-qt (on Linux). If you upgrade after DIP0003 activation and you were
using version < 0.13 you will have to reindex (start with -reindex-chainstate
or -reindex) to make sure your wallet has all the new data synced. Upgrading from
version 0.13 should not require any additional actions.

When upgrading from a version prior to 0.14.0.3, the
first startup of Absolute Core will run a migration process which can take a few minutes
to finish. After the migration, a downgrade to an older version is only possible with
a reindex (or reindex-chainstate).

Downgrade warning
-----------------

### Downgrade to a version < 0.14.0.3

Downgrading to a version smaller than 0.14.0.3 is not supported anymore due to changes
in the "evodb" database format. If you need to use an older version, you have to perform
a reindex or re-sync the whole chain.

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
