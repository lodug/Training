#! /bin/bash

function hello()
{
    echo "Hello"
    
    #call function now
    now
}

function now()
{
    echo "it is $(date +%r)"  
}

function hello1()
{
    #$0 = the script itself; $1 = Jason
    echo "Hello $1"

}

function hello2()
{
    for NAME in $@
    do
        echo "Hello $NAME"
    done

}

#call function hello
hello

hello1 Jason

hello2 Jas Dan Ruan
