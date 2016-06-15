#Reference: http://www.tldp.org/LDP/abs/html/x17837.html

String="This is a string of words."

read -r -a Words <<< "$String"
# -a: Option to read

echo "First word in String is: ${Words[0]}" # This
echo "Second word in String is: ${Words[1]}" # is
