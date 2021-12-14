#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "util.h"
#include <time.h>

double countTime(char *filename, size_t block_size, size_t block_count)
{

    // timer start time
    clock_t begin;
    double time_spend;
    unsigned int i;
    begin = clock();

    readUtil(filename, block_size, block_count);
    time_spend = (double)(clock() - begin) / CLOCKS_PER_SEC;

    return time_spend;
}

int main(int argc, char *argv[])
{
    // assume this file is very large
    char *filename;
    size_t block_size;
    filename = argv[1];
    sscanf(argv[2], "%lu", &block_size);

    size_t block_count = 1;
    double time = 0;

    // loop until runtime falls between 5 - 15 seconds
    while (time < 5)
    {
        double time = countTime(filename, block_size, block_count);
        block_count *= 2;
    }
    printf("%f", time);

    exit(0);
}
