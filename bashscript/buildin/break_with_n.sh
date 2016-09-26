# Reference: http://tldp.org/LDP/abs/html/loopcontrol.html
for outerloop in 1 2 3 4 5
do
  echo -n "Group $outerloop: "

  for innerloop in 1 2 3 4 5
  do
    echo -n "$innerloop"

    if [ "$innerloop" -eq 3 ]
    then
      break 3
    fi
  done
  echo
done

echo

exit 0
