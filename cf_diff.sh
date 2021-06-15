#!/bin/bash
set -xeuo pipefail

files=`git diff --name-only`
for file in $files; do
  if [[ "$file" == *.h  || "$file" == *.cc || "$file" == *.cpp ]]; then
    clang-format -style=file -i $file
  fi
done