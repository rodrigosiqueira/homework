declare -a arraylife

arraylife[0]=23
arraylife[1]=24
arraylife[2]=25
arraylife[3]=26

declare -i var
var=0
until test $var = 4
do
  value=$var
  echo ${arraylife[value]}
  (( var++ ))
done
