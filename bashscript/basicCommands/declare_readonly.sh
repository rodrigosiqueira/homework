declare -r var1=1

echo "var1 = $var1"

echo "We expect an error after var++: "
(( var1++ ))
