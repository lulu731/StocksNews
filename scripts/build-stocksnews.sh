#!/bin/bash

lulu731=/home/travis/build/lulu731
cd $lulu731/StocksNews
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
cd ..


