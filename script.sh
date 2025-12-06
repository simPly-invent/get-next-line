#!/bin/sh 

for i in `seq 0 1024`
    do touch test_$i.txt;
    echo 42 > test_$i.txt;
done