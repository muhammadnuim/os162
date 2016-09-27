teks=`cat $1`
echo "$teks"

len=`expr length $teks`
echo "$len"

stringA=`expr substr $teks 5 4`
echo "$stringA"

stringB=`expr "$teks" : '.*\(.....\)'`
echo "$stringB"

jlhcc=`grep -o cc $1 | wc -w`
echo "$jlhcc"
jlhZZ=`grep -o ZZ $1 | wc -w`
echo "$jlhZZ"

a=10
b=2
echo `expr $a + $b`
echo `expr $a - $b`
c=`expr $a \* $b`
echo "$c"
echo `expr $a / $b`
echo `expr $a - 5`

text=`cat $1`
for ((a=0;a<10;a++))
do

	echo "$text"
done
