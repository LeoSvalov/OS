touch out.txt
echo 0 >> out.txt
  
for (( i = 0; i < 100; i++ )); do
	N=`tail -1 out.txt`
	N=$((N+1))
	echo $N >> out.txt 
done
