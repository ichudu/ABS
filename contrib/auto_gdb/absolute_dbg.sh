#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.absolutecore/absoluted.pid file instead
dash_pid=$(<~/.absolutecore/testnet3/dashd.pid)
sudo gdb -batch -ex "source debug.gdb" absoluted ${absolute_pid}
