#!/bin/bash
for file in $(/bin/ls); do ./compile.sh $file; done
