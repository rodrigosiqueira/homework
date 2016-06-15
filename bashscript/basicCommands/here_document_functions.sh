GetPersonalData ()
{
  read firstname
  read lastname
  read address
  read city
  read state
  read zipcode
}

GetPersonalData <<REC001
Bozo
Boooo
2343
Boozzzeeeen
MT
2932
REC001

echo '------------------'
echo "$firstname $lastname"
echo "$address"
echo "$city, $state $zipcode"
echo

exit 0
