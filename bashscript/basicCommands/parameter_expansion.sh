<<<<<<< Updated upstream
function separator()
{
  echo '==============================================='
}

separator
echo 'Test: ${#parameter}.'

s='abc'
echo ${#s}

separator
echo 'Test (prefix): ${parameter#word} - use it in Hello-word string.'
str='Hello-world'
echo ${str#Hel}

separator
echo 'Test (sufix): ${parameter%word} - use it in Hello-word string.'
str='Hello-world'
echo ${str%rld}

separator
echo 'Test (replace): ${parameter/pattern/string} - replace ll by uu in Hello-word string.'
str='Hello-word'
echo ${str/ll/uu}

separator
echo 'Test (upper/lower): ${parameter^^pattern} - Make it upper or lower case.'
str='abc'
echo ${str^^b}

=======
string=1234567abcdefgh

echo '----------------------------'
echo $string
echo '----------------------------'

echo -n '${parameter:-word} --> '
echo ${string:-'abc'}

echo -n '${parameter:=word} --> '
echo ${string:=xpto}

echo -n '${string:?word} --> '
echo ${string:=xpto}

echo -n '${string:+word} --> '
echo ${string=xpto}

echo -n '${string:offset} --> '
echo -n '${string:7} --> '
echo ${string:7}

echo -n '${string:7:0} --> '
echo ${string:7:0}
echo -n '${string:7:2} --> '
echo ${string:7:2}
echo -n '${string: -7:2} --> '
echo ${string: -7:2}

echo -n '${string: -7:-2} --> '
echo ${string: -7:-2}

echo '----------------------------'
echo 'set -- 123456789abcdefgh'
set -- 123456789abcdefgh
echo '----------------------------'
echo -n '${1:7} --> '
echo ${1:7}
echo -n '${1:7:2} --> '
echo ${1:7:2}
>>>>>>> Stashed changes
