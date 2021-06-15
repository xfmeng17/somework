#!/bin/bash
set -xeuo pipefail

dirpath=$1
# 判断目录存在
if [ -z "$dirpath" ]; then
  echo "dirpath="$dirpath" is empty"
  exit 1
fi

# 遍历目录下的目标文件
files=$(ls $dirpath)
echo $files
for file in $files; do
  if [[ "$file" == *.h  || "$file" == *.cc || "$file" == *.cpp ]]; then
    clang-format -style=file -i $dirpath$file
  fi
done