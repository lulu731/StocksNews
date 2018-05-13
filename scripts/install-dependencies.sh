#!/bin/bash

lulu731=/home/travis/build/lulu731
cd $lulu731
mkdir boost
cd boost
wget https://dl.bintray.com/boostorg/release/1.67.0/source/boost_1_67_0.tar.bz2
tar --bzip2 -xf boost_1_67_0.tar.bz2
cd boost_1_67_0
./bootstrap.sh --prefix=../installation --with-libraries=test,system,filesystem
./b2 -d0 install
cd $lulu731/StocksNews



