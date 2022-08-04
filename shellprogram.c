#!/bin/bash
echo -n "enter the number:"
read num
if['expr $num%2==0']
then 
   echo "$num is even"
else
   echo "$num is odd"
fi
