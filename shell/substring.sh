#!/bin/bash

## https://www.cnblogs.com/iamdevops/p/5602885.html
## https://cloud.tencent.com/developer/article/1398436

file=dir1/dir2/dir3/my.file.txt 
echo ${file#*/}   # dir2/dir3/my.file.txt
echo ${file##*/}  # my.file.txt
echo ${file%*/}   # 没变化，不好使
echo ${file%/*}   # dir1/dir2/dir3 

