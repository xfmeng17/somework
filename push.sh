#!/bin/bash

MESSAGE=`date +"%Y-%m-%d %T"`

git add .
git commit -m "${MESSAGE}"
git push origin master

