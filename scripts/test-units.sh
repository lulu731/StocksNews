#!/bin/bash

stocksnews=/home/travis/build/lulu731/StocksNews
(
 cd $stocksnews/build/tests || exit
 ./tests
 cd $stocksnews 
)
