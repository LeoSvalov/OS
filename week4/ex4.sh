while true; do
	read string
	string="$string </dev/null &>/dev/null &"
	eval $string 
done