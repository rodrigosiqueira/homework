#!/bin/bash

# create the co-process
coproc myproc {
    bash
}

# send a command to it (echo a)
echo 'echo a' >&"${myproc[1]}"

# read a line from its output
read line <&"${myproc[0]}"

# show the line
echo "$line"
