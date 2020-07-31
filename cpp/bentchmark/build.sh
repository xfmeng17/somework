#!/bin/bash

#g++ -Wall -std=c++14 test.cc -pthread -lbenchmark
#g++ -g -Wall -std=c++11  ssplit.cc -o ssplit -lbenchmark -lboost_system -pthread
echo $1
echo $2
g++ -g -Wall -std=c++11 $1 -o $2 -lbenchmark -lboost_system -pthread
