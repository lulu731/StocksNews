#!/bin/bash

#stocksnews=~/build/lulu731/StocksNews

# cd $stocksnews/build || exit $?
 cd build 
 make test
 exit_val=$?
 #cd $stocksnews
 cd .. 
 exit $exit_val

