# Reference: http://unix.stackexchange.com/questions/175648/use-config-file-for-my-shell-script
typeset -A config
config=(
  [username]="root"
  [password]=""
  [hostname]="localhost"
)

while read line
do
  if echo $line | grep -F = &>/dev/null
  then
    varname=$(echo "$line" | cut -d '=' -f 1)
    config[$varname]=$(echo "$line" | cut -d '=' -f 2-)
  fi
done < configuration.conf

echo ${config[username]}
echo ${config[password]}
echo ${config[hostname]}
echo ${config[PROMPT_COMMAND]}
