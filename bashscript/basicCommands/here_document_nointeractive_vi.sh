#!/bin/bash
# Reference: http://www.tldp.org/LDP/abs/html/here-docs.html

# Noninteractive use of 'vi' to edit a file.
# Emulates 'sed'.

E_BADARGS=85

if [ -z "$1" ]
then
	echo "Usage: `basename $0` filename"
	exit $E_BADARGS
fi

TARGETFILE=$1

# Insert 2 lines in file, then save.
#---- Begin here document ----
vi $TARGETFILE << EOF
i
This is line 1 of the example file. Can you see??? hehehe
We just started with i, and now we gonna finish! Look below:
^[
ZZ
EOF
#---- End here document ----
exit
