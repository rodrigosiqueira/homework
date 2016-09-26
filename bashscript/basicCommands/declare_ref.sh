function reference_test()
{
  declare -n ref=$1
  echo "Hello, I am the value inside reference: $ref"
  (( ref++ ))
}

function no_reference()
{
  ref=$1
  echo "I am not using ref, my value: $ref <- can you see?"
  (( ref++ ))
}

function extract_target_name()
{
  declare -n ref=$1
  targetname="$(basename "$ref")"
  targetname=${targetname/.csv/''}
  ref=$targetname
}

var=3

reference_test var
echo "I am outside, and you can see my new value: $var"
no_reference var
echo "I am from no ref: $var"

echo '--------------'
echo 'Realistic test'

dir="blablabla/xpto.csv"
targetname="$(basename "$dir")"
echo "target: $targetname"
extract_target_name targetname
echo "After: $targetname"
