#!/bin/bash

size=(1 2 3 4 5 6)

for i in ${size[@]}; do
	tf="t"$i
	fallocate -l $i"G" $tf
	#time ./checkfile $tf
	time sha1sum $tf
	rm $tf

done
exit 0
