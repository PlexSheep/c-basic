#!/bin/bash
echo "compiling $1 ..."
noext=$(echo "$1" | cut -f 1 -d '.')

# to treat warnings as errors, use the following line
#gcc $1 -o bin/$noext -lm -Werror=format
#
gcc $1 -o bin/$noext -lm
