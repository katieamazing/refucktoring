#!/bin/bash

expect lander_test.tcl | diff -u - lander_gold.txt

if [ $? -eq 0 ]
then
   echo "OK!";
fi
