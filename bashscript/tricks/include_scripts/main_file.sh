DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$DIR" ]]; then
  DIR="$PWD"
fi

. "$DIR/included_one.sh"
. "$DIR/included_two.sh"
