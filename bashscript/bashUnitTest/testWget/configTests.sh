#!/bin/bash

setUp()
{
  originalPath=$PATH
  PATH=$PWD:$PATH
}

tearDown()
{
  PATH=$originalPath
  export TEST_WGET_FAILURE=
}

testFailsWhenArgumentNotSupplied()
{
  ./configRetriever.sh > /dev/null
  returnCode=$?
  assertEquals "Script fail when no argument" 1 $returnCode
}

testFailsWhenwgetFails()
{
  export TEST_WGET_FAILURE=1
  ./configRetriever.sh "testUrl" > /dev/null
  returnCode=$?
  assertEquals "Script should fail when wget fails" 2 $returnCode
}

testSuccessAllAround()
{
  response=$(./configRetriever.sh "testUrl")
  echo "$response" | grep -qE "Success"
  returnCode=$?
  assertEquals "Script was not successful" 0 $returnCode
}

. shunit2
