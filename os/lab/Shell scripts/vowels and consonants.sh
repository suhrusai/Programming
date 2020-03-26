read -p "Enter a String: " a
len=`expr $a | wc -c`
echo $len
i=1
consonants=0
v=0
v1="a"
v2="e"
v3="i"
v4="o"
v5="u"
while [ $i -lt $len ]
do
	c=  `expr $a | cut -c $i`
	echo $c
	if [ X"$c" = X"$v1" ]
	then
		v=`expr $v + 1`
	elif [ X"$c" = X"$v2" ]
	then
		v=`expr $v + 1`
        elif [ X"$c" = X"$v3" ]
	then
		v=`expr $v + 1`
	elif [ X"$c" = X"$v4" ]
        then
		v=`expr $v + 1`
        elif [ X"$c" = X"$v5" ]
	then
		v=`expr $v + 1`
	else	
		consonants=`expr $consonants + 1`
	fi
	i=`expr $i + 1`
done
echo "vowel count: "$v

