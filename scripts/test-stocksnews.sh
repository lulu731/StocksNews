#!/bin/bash

cd build 
make test
exit_val=$?
#cd .. 
exit $exit_val

