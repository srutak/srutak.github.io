#!/bin/sh
if  test $# -eq 0
then
    echo "e.g. to run 2 actors and 2 audience clients:"
    echo "Runtclient.sh localhost 10123 2"
    exit
fi

total=$3
index=1
while test $index -le $total
do
 xterm -e  tclient $1 $2 &
 echo AUDIENCE
 xterm -e  tclient $1 $2 a &
 echo ACTOR
 index=`expr $index + 1`
 sleep 2
done
