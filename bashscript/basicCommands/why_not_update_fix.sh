i=0
cat $1 | (while read line; do
echo $line
i=$(( i + 1 ))
done
echo $i)
