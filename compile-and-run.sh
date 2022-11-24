#!/bin/bash
noext=$(echo "$1" | cut -f 1 -d '.')
./compile.sh $1
./bin/$noext $2 $3 $4 $5 $6 $7 $8 $9
