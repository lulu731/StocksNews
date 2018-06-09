#!/bin/bash

stocksnews=~/build/lulu731/StocksNews
(
 cd $stocksnews/build/tests || exit
 ./tests
 exit_val=$?
 cd $stocksnews
 exit $exit_val
)
