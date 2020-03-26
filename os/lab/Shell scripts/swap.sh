read -p 'Enter a: ' a
read -p 'Enter b: ' b
a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`
echo 'a='$a'    b='$b
