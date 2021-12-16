#!/bin/bash

echo -e "Running experiment for part 2 \n"

for (( i=1024; i <= 134217728 ; i*=2 )); do
    # echo "block size: $i" 
    ./run2 4GBFILE $i
    echo -e "----------------------- \n"
done
