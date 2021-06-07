#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.absolutecore/absoluted.pid file instead
absolute_pid=$(<~/.absolutecore/testnet3/absoluted.pid)
sudo gdb -batch -ex "source debug.gdb" absoluted ${absolute_pid}
