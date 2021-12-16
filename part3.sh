#!/bin/bash

echo -e "Running experiment for part 3 \n"

for (( i=4; i <= 134217728 ; i*=2 )); do
    echo "block size: $i" 
    ./run2 temp_30GB_file $i
    echo -e "----------------------- \n"
done
