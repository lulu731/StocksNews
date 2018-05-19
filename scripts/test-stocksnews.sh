#!/bin/bash

stocksnews=~/build/lulu731/StocksNews
(
 cd $stocksnews/build || exit
 ctest
 cd $stocksnews 
)
