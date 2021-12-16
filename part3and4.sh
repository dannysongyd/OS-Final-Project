#!/bin/bash

echo -e "Running experiment for part 3 and 4 \n"
declare -i FILESIZE 
FILESIZE=4294967296

filename="4GBFILE"

for (( i=1024; i <= 134217728 ; i*=2 )); do

    sudo purge
    temp=$(($FILESIZE/$i))

    echo -e "Block Size: $i"
    echo -e "Uncached:"
    ./run3 $filename $i $temp

    echo -e ""
    echo -e "Cached:"
    ./run3 $filename $i $temp

    echo -e ""
    echo -e "dd command:"
    sudo purge
    dd if=$filename of=/dev/null bs=$i

    echo -e "----------------------- \n"

 
done