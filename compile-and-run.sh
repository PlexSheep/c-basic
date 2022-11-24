#!/bin/bash
noext=$(echo "$1" | cut -f 1 -d '.')
echo "compiling $1 ..."
gcc $1 -o bin/$noext -lm
./bin/$noext $2 $3 $4 $5 $6 $7 $8 $9
