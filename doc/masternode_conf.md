Masternode config
=======================

Absolute Core allows controlling multiple remote masternodes from a single wallet. The wallet needs to have a valid collateral output of 2500 coins for each masternode and uses a configuration file named `masternode.conf` which can be found in the following data directory (depending on your operating system):
 * Windows: %APPDATA%\AbsoluteCore\
 * Mac OS: ~/Library/Application Support/AbsoluteCore/
 * Unix/Linux: ~/.absolutecore/

`masternode.conf` is a space separated text file. Each line consists of an alias, IP address followed by port, masternode private key, collateral output transaction id and collateral output index.

Example:
```
mn1 127.0.0.2:18888 4hcmvB9TQf8xUSy4sTfVqqzifEq9J5Ef6H1VFhRmA8sZJs8j1vw 31e78e9f592781bdc043e883909e9fd198ef64ad154461d8ca304ed62723678c 0
mn2 127.0.0.4:18888 4hcmzftTQf8xUSy4sTfVqqgt7Eq9J5Ef6H1VFhRmA8sZJs6jixv b09efd8a9e5a9fca44a00g1095e4427542f35d7886fba20ae5dc61176062a585 1
```

In the example above:
* the collateral of 2500 ABS for `mn1` is output `0` of transaction [7603c20a05258c208b58b0a0d77603b9fc93d47cfa403035f87f3ce0af814566]
* the collateral of 2500 ABS for `mn2` is output `1` of transaction [5d898e78244f3206e0105f421cdb071d95d111a51cd88eb5511fc0dbf4bfd95f]

_Note: IPs like 127.0.0.* are not allowed actually, we are using them here for explanatory purposes only. Make sure you have real reachable remote IPs in you `masternode.conf`._

The following RPC commands are available (type `help masternode` in Console for more info):
* list-conf
* start-alias \<alias\>
* start-all
* start-missing
* start-disabled
* outputs
