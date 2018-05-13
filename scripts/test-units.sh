#!/bin/bash

stocksnews=/home/travis/build/lulu731/StocksNews
cd $stocksnews/tests
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
./tests
cd $stocksnews 


