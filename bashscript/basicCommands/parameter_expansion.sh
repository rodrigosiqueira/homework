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

