#!/bin/bash

SRC_FILE = 'ls -R | grep -i ".c"'

echo $SRC_FILE

rm output/*

for fsrc in $SRC_FILE
do 
    nfile = "${fsrc%.c}.o"
    gcc -c -o output/$nfile $fsrc
done

cd output
OBJ_FILE = 'ls -R | grep -i ".o"'
gcc -o myapp $OBJ_FILE