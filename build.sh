#!/bin/bash

# compile every .c file
gcc run.c -o run
gcc run2.c -o run2
gcc run3.c -o run3
gcc run5.c -o run5
gcc fast.c -o fast

# # craete an 4GB file if it doesn't exist
# if [ ! -f 4GBFILE ]; then
#     mkfile -n 4g 4GBFILE
# fi

# # download ubuntu image if it doesn't exist
# if [ ! -f ubuntu ]; then
#     curl -o ubuntu 'http://www.releases.ubuntu.com/21.04/ubuntu-21.04-desktop-amd64.iso'
# fi