#!/bin/bash

stocksnews=~/build/lulu731/StocksNews
(
 cd $stocksnews/build || exit $?
 make test
 exit_val=$?
 cd $stocksnews
 exit $exit_val 
)
