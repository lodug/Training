#! /bin/bash

#ppercase should be the variables
MY_SHELL="bash"

#assign command output to a variable
SERVER_NAME=$(hostname)

echo "I like the $MY_SHELL shell"

echo "I like the ${MY_SHELL} shell"

echo "I like the ${MY_SHELL}ing shell"

echo "you are running this script on ${SERVER_NAME}"

if  [ "$MY_SHELL" = "bash" ]
then
    echo "you like the bash shell"
else
    echo "you don't like the bash shell"
fi

for COLOR in red green blue
do

    echo "COLOR: $COLOR"

done

COLORS="red green blue"
for COLOR in $COLORS
do

    echo "COLOR: $COLOR"

done