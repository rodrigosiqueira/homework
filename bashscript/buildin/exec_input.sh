# Reference: http://wiki.bash-hackers.org/commands/builtin/exec

exec 3< input.txt

# Read one line from the file

read -u 3 LINE

read LINE <&3

exec 3<&-
