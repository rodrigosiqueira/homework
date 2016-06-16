#!/bin/bash

# Reference: http://www.mikewright.me/blog/2013/10/31/shunit2-bash-testing/
# This is a simple script that we use for try to test

if [ -z "$1" ]
then
  echo "Missing required command line url"
  exit 1
fi

wget https://github.com/Kuniri/kuniri/blob/master/README.md
if [ ! $? -eq 0 ]
then
  echo "Failed to get the file from the web"
  exit 2
fi

echo "Success"
