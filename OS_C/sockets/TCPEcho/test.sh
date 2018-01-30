#!/bin/sh

i="0"
while [ $i -lt 10000 ]
do
	./echo-client 127.0.0.1 "gogogo num : $i" 3456
	i=$[$i+1]
done
