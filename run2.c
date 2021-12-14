#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // assume this file is very large
    char *filename;
    size_t block_size;
    filename = argv[1];
    sscanf(argv[2], "%lu", &block_size);
}