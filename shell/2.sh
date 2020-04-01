#!/bin/bash

echo "PID for 2.sh = $$"
echo "In 2.sh get variable A=$A from 1.sh"

A=2
export A

echo -e "In 2.sh: variable A=$A\n"
