#!/bin/sh
module="fakeMemory"
device="osp"

# invoke rmmod with all arguments we got
/sbin/rmmod $module $* || exit 1

# Remove stale nodes
rm -f /dev/${device}[nr] 






