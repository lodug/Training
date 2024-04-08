#! /bin/bash

HOST="google.com"

#In this example, if the ping command exits with a 0 exit status, then "google.com reachable" will be echoed to the screen
ping -c 1 $HOST && echo "$HOST reachable"

