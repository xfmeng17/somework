#!/bin/sh

clfall=`find . -iname '*.cc' -o -iname '*.h' -o -iname '*.h.in' -o -iname '*.cpp' | xargs clang-format -i --style=google`
clf=`clang-format -style=google -i`

