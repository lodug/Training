#! /bin/bash

#start the server
echo "run server"
./serverb &

sleep 3

#start the client
echo "run client"
./clientb

echo "script executed"

