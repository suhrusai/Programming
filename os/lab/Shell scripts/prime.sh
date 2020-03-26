echo "enter num to be checked"
read n
i=2
flag=0
while [ $i -le $((n/2)) ]
do
	if [ $((n%i)) -eq 0 ]
		 then
		 flag=1
		 break								
	 fi										       
	 i=$((i + 1))
done
if [ $i -eq $(($((n/2)) + 1)) ]

then
       	echo "Prime"
else
	   echo "Not Prime"
fi
