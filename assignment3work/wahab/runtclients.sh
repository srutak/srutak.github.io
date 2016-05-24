#!/bin/sh
if  test $# -eq 0
then
    echo "e.g. to run 2 panclients and 2 audclients:"
    echo "runpclient.sh localhost 10123 2"
    exit
fi

total=$3
index=1
while test $index -le $total
do
 xterm -e  ./panclient $1 $2 &
 echo PANELIST
 xterm -e  ./audclient $1 $2 p &
 echo AUDIENCE
 index=`expr $index + 1`
 sleep 2
done
