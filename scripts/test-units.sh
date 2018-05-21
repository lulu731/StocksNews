#!/bin/bash

stocksnews=~/build/lulu731/StocksNews
(
 cd $stocksnews/build/tests || exit
 ./tests
 cd $stocksnews
 exit $?
)
