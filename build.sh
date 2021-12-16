#!/bin/bash

# compile every .c file
gcc run.c -o run
gcc run2.c -o run2
gcc run3.c -o run3
gcc run5.c -o run5
gcc fast.c -o fast

# craete an 4GB file
mkfile -n 4g 4GBFILE
