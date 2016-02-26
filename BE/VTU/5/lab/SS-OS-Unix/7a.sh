echo "the number of arguments provided are:$#"
length=$#
echo "the reverse order the arguments:"
while [ $length -ne 0 ] 
do
 eval echo \$$length
 length=`expr $length - 1`
done
