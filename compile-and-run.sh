#!/bin/bash
noext=$(echo "$1" | cut -f 1 -d '.')
gcc $1 -o bin/$noext
./bin/$noext $2 $3 $4 $5 $6 $7 $8 $9
