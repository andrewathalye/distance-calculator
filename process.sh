#!/bin/sh
# ./process.sh NUMBER OF LINES
# Reads from sorted distance data (sort.txt)
# Unsorted distance data (dist.txt)
# and raw output data from LocationLogger in order to determine nearest
# players.
NUM=$1
for i in $(seq 1 $NUM)
do
	VAL=$( head -n$i sort.txt | tail -n1 )
	LINE=$( grep -n "$VAL" dist.txt | head -n 1 | cut -d: -f1)
	head -n$LINE data.txt | tail -n1 | cut -d' ' -f1,2
	echo $VAL
done
