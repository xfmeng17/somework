#!/bin/bash

A=1

echo "before exec/source/fork: PID for 1.sh = $$"

export A
echo "In 1.sh: variable A=$A"

case $1 in
        --exec)
                echo -e "==> using exec…\n"
                exec ./2.sh ;;
        --source)
                echo -e "==> using source…\n"
                . ./2.sh ;;
        *)
                echo -e "==> using fork by default…\n"
                ./2.sh ;;
esac

echo "after exec/source/fork: PID for 1.sh = $$"
echo -e "In 1.sh: variable A=$A\n"
