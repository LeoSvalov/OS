# version with preventing a race of threads.

touch out.txt
echo 0 >> out.txt
  
for (( i = 0; i < 100; i++ )); do
	N=`tail -1 out.txt`
	N=$((N+1))
	echo $N >> out.txt 
done
if ln out.txt out.txt.lock 
then
	for (( i = 0; i < 100; i++ )); do
		LASTNUMBER=`tail -1 out.txt`
    	LASTNUMBER=$((LASTNUMBER+1))

    	echo $LASTNUMBER >> out.txt
	done
	rm out.txt.lock
fi