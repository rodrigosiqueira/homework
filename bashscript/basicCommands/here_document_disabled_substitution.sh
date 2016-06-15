# http://www.tldp.org/LDP/abs/html/here-docs.html
NAME="John Doe"
RESPONDENT="the author of this fine script"

echo 'Disabled substitution'

cat <<'EndOfFile'

Hello, there, $NAME.
Greetings to you, $NAME, from $RESPONDENT.

EndOfFile

echo 'Normal substitution'
cat <<EndOfFile

Hello, there, $NAME.
Greetings to you, $NAME, from $RESPONDENT.

EndOfFile


echo 'Special character test'

cat <<"SpecialChar"

Directory listing would follow if limit
string were not quoted.
`ls -l`

Arithmetic expasion would take place if limit string
wre not quoted.
$((5 + 3))

A single backslash would echo if limit string were not
quoted.
\\

SpecialChar

exit
