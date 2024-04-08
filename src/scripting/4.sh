#!/bin/bash

cd ~/Practice/C++/Training/src/scripting
for FILE in *.txt
do
    echo "Copying $FILE"
    cp $FILE ~/Practice/C++/Training/src/scripting/test
done