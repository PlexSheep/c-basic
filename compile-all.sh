#!/bin/bash
mkdir -p bin
returnCode=0
echo -e "compiling all files in working directory $(pwd)\n"
for file in $(/bin/ls *.c); 
do 
    echo "compiling $file ..."
    noext=$(echo "$file" | cut -f 1 -d '.')
    gcc $file -o bin/$noext -lm
    if [ "$?" -ne 0 ]
    then
        echo -e "\nERROR: could not compile $file !\n";
        returnCode=1;
    fi
done
echo -ne "\nfinished compiling all source files. ";
if [ "$returnCode" -eq 0 ]
then
    echo -ne "No errors occured.";
else
    echo -ne "Some errors occured.";
fi
echo "";
exit $returnCode
