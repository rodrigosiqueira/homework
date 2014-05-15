#!/bin/sh
module="fakeMemory"
device="osp"
mode="664"

# Group: since distributions do it differently, look for wheel or use staff
if grep '^staff:' /etc/group > /dev/null; then
    group="staff"
else
    group="wheel"
fi

# invoke insmod with all arguments we got
# and use a pathname, as newer modutils don't look in . by default
/sbin/insmod -f ./module/$module.ko $* || exit 1

major=`awk '{if ($2 == "osp") print ($1)}' /proc/devices`

# Remove stale nodes and replace them, then give gid and perms
# Usually the script is shorter, it's simple that has several devices in it.

rm -f /dev/${device}[nr]
mknod /dev/${device}n c $major 0
mknod /dev/${device}r c $major 1
chgrp $group /dev/${device}[nr] 
chmod $mode  /dev/${device}[nr]

