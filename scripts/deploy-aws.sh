#!/bin/bash

cd ~/StocksNews
cmd='git fetch'
$cmd >> deploy.txt
cd ~/StocksNews/build
cmd='make install'
$cmd >> deploy.txt
