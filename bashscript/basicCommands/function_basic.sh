Hello_v1 () {
  echo "Hello v1"
}

function Hello_v2 () {
  echo "Hello v2"
}

function Hello_v3 {
    echo "Hello v3"
}

Hello_param () {
  echo "Hello $1 $2"
}

Hello_inpect ()
{
  echo "How about func name? Me: $FUNCNAME"
  echo "parameters: $#"
  echo "Inspect: $0 --> $1 $2 $3"
}

Hello_return_test ()
{
  return 42
}

Hello_inline () { echo "Hello inline"; }
function Hello_inline2 { echo "Hello inline 2"; }

Hello_v1
Hello_v2
Hello_v3
Hello_param Tic Tac
Hello_inpect Woooo Tac Toe

Hello_inline
Hello_inline2

Hello_return_test
hugeQuestion=$? # $? Capture the last value
echo "The answer: $hugeQuestion"
