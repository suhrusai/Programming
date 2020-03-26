read -p 'Enter a: ' a
read -p 'Enter b: ' b
read -p 'Enter a: ' c
if [ $a -gt $b -a $a -gt $c ]
then
	        echo "a= "$a"  is the gretest"
	elif [ $c -gt $a -a $c -gt $b ]
	then
		        echo "c= "$c"  is the gretest"
		else
			        echo "b= $b is the gretest"
			fi
