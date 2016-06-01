declare -i number
# The script will treat subsequent occurrences of 'number' as an integer

number=3
echo "Number = $number" # Number = 3

echo "We tried:  number=three"
number=three
echo "So... we expect integer behaviour"
echo "Number = $number"
