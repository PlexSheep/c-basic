#!/bin/bash
mkdir -p bin
echo "compiling $1 ..."
noext=$(echo "$1" | cut -f 1 -d '.')
gcc $1 -o bin/$noext -lm
