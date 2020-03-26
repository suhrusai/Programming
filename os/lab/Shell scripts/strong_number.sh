echo enter n
read n
sum=0
k=$n
while [ $n -gt 0 ]
do
	d=`echo $n%10|bc`
	fact=1
	i=1
	while [ $i -le $d ]
	do
	fact=`expr $fact \* $i`
	i=`expr $i + 1`
	done
	sum=`expr $sum + $fact`
	n=`expr $n / 10`
done
if [ $sum -eq $k ]
then
	echo strong number
else
	echo not strong number
fi
