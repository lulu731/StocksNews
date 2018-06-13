#!/bin/bash

#stocksnews=~/build/lulu731/StocksNews

# cd $stocksnews/build/tests || exit
  cd build/tests
 ./tests
 exit_val=$?
# cd $stocksnews
 cd ..
 cd ..
 exit $exit_val

