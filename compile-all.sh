#!/bin/bash
echo "compiling all files in working directory $(pwd)"
for file in $(/bin/ls); do ./compile.sh $file; done
