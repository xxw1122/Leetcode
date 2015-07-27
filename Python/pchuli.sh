ls /Users/lawrence/Documents/Coding/Interview/Lintcode/Cpp/*.cpp | while read myfile
do
   new=`echo "$myfile" | sed 's/\ /-/g'`
   echo $new
   mv -f "$myfile" $new
done