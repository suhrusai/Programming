read -p "Enter x: " x
read -p "Enter n: " n
mul=1
i=0
while [ $i -lt $n ]
do	
	mul=`expr $mul \* $x`
	i=`expr $i + 1`
done
echo $mul
