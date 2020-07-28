#!/bin/bash

#g++ -Wall -std=c++14 test.cc -pthread -lbenchmark
g++ -g -Wall -std=c++11  ssplit.cc -o ssplit -lbenchmark -lboost_system -pthread
