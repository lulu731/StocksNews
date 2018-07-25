#!/bin/bash

chmod +x scripts/install-dependencies.sh
./scripts/install-dependencies.sh

mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make install
exit_val=$? 
cd ..
cp -r ./stocks/ ~/stocks_news
exit $exit_val
