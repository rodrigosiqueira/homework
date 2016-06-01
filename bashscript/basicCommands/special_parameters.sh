function xpto()
{
  echo "*: $*"
  echo "@: $@"
  echo "#: $#"
  echo "-: $-"
  echo "$: $$"
  echo "!: $!"
  echo "_: $_"
}

xpto 1 2 3
