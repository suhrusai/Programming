read -p "Enter a: " a
for i in 1 2 3 4 5 6 7 8 9 10
do
	mul=`expr $a \* $i`
	echo $a" * "$i" =" $mul
done

