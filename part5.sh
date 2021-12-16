#!/bin/bash

echo -e "Running experiment for part 5 \n"

for (( i=1024; i <= 16777216 ; i*=2 )); do
    echo -e "Block Count: $i"
    ./run5 4GBFILE $i
    echo -e "----------------------- \n"

 
done