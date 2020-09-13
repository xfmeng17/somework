#!/bin/bash

g++ main.cc person.pb.cc -I. -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf -lpthread -static
./a.out

