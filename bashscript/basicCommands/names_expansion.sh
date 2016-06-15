for ((i=0;i<5;i++)); do
	touch "test$i.txt"
done

echo '==================================='
echo 'ls @(test*)'
ls @( test* )

echo '==================================='
echo 'ls !(*.sh)'
ls !( *.sh )
