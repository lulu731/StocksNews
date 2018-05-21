#!/bin/bash

lulu731=/home/travis/build/lulu731
(
  cd /home/travis/build/lulu731/StocksNews || exit
  mkdir build
  cd build || exit
  cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
  make
  cp -r ../stocks/ .
  cd ..
)
