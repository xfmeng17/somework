#!/bin/bash
set -xeuo pipefail

filepath=$1
if [ "$filepath" == *.h  || "$filepath" == *.cc || "$filepath" == *.cpp ]; then
  clang-format -style=file -i $filepath
fi