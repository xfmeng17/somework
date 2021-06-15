#!/bin/bash

# bazel build ...
bazel build ... --copt="-ggdb3" --strip="never" --compilation_mode=dbg
