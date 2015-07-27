ls /Users/lawrence/Documents/Coding/Interview/Leetcode/Python/*.py | while read myfile
do
   new=`echo "$myfile" | sed 's/\ /-/g'`
   echo $new
   mv -f "$myfile" $new
done