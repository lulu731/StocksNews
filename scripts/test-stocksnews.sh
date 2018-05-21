#!/bin/bash

stocksnews=~/build/lulu731/StocksNews
(
 cd $stocksnews/build || exit
 make test
 cd $stocksnews
 exit $? 
)
