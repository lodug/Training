#! /bin/bash

echo "directory: $(pwd)"

#compile server.cpp
g++ ~/Practice/C++/Training/Task/Task7/StartAutomatically/server.cpp -o ~/servera
mv ~/servera ~/Practice/C++/Training/Task/Task7/StartAutomatically

#compile client.cpp
g++ ~/Practice/C++/Training/Task/Task7/StartAutomatically/client.cpp -o ~/clienta
mv ~/clienta ~/Practice/C++/Training/Task/Task7/StartAutomatically

#start the server
echo "run server"
~/Practice/C++/Training/Task/Task7/StartAutomatically/servera &

sleep 1

#start the client
echo "run client"
~/Practice/C++/Training/Task/Task7/StartAutomatically/clienta 

sleep 1

mv ~/outputServer.txt ~/Practice/C++/Training/Task/Task7/StartAutomatically

mv ~/outputClient.txt ~/Practice/C++/Training/Task/Task7/StartAutomatically

echo "script executed"

