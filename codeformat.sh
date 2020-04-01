#!/bin/sh

find . -iname '*.cc' -o -iname '*.h' -o -iname '*.h.in' -o -iname '*.cpp' | xargs clang-format -i --style=google

