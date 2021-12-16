#!/bin/bash

echo -e "Running experiment for part 3 and 4 \n"
declare -i FILESIZE 
FILESIZE=4294967296
# echo "$FILESIZE" 
for (( i=1024; i <= 134217728 ; i*=2 )); do

    sudo purge
    temp=$(($FILESIZE/$i))

    echo -e "Block Size: $i"
    echo -e "Uncached:"
    ./run3 4GBFILE $i $temp

    echo -e ""
    echo -e "Cached:"
    ./run3 4GBFILE $i $temp

    echo -e ""
    echo -e "dd command:"
    sudo purge
    dd if=4GBFILE of=/dev/null bs=$i

    echo -e "----------------------- \n"

 
done