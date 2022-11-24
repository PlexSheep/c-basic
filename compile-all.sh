#!/bin/bash
returnCode=0
echo -e "compiling all files in working directory $(pwd)\n"
for file in $(/bin/ls *.c); 
do 
    ./compile.sh $file; 
    if [ "$?" -ne 0 ]
    then
        echo -e "\nERROR: could not compile $file !\n";
        returnCode=1;
    fi
done
exit $returnCode
