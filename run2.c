#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <time.h>

void readUtil(char *filename, size_t block_size, size_t block_count)
{
    int fd;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    unsigned int xor = 0;

    unsigned int *buf = malloc(block_size);
    ssize_t read_size;

    // read
    for (int i = 0; i < block_count; i++)
    {

        while ((read_size = read(fd, buf, block_size)) > 0)
        {
        }
    }

    // free
    free(buf);

    close(fd);
}
double countTime(char *filename, size_t block_size, size_t block_count)
{

    // timer start time
    clock_t begin;
    clock_t end;
    double time_spend;

    begin = clock();
    readUtil(filename, block_size, block_count);
    end = clock();

    time_spend = (double)(end - begin) / CLOCKS_PER_SEC;

    return time_spend;
}

int main(int argc, char *argv[])
{
    // assume this file is very large
    char *filename;
    size_t block_size;
    filename = argv[1];
    sscanf(argv[2], "%lu", &block_size);

    size_t block_count = 1.0;
    double time = 0;

    // loop until runtime falls between 5 - 15 seconds
    while (time < 3 && (block_size * block_count * 2 <= 4294967296))
    {
        // printf("time: %f \n", time);
        block_count *= 2.0;
        time = countTime(filename, block_size, block_count);
        // printf("Time %f \n", time);
        // printf("File size: %f GB \n", (block_size * block_count) / (double)(1024 * 1024 * 1024));
        // printf("File size: %lu Bytes \n", (block_size * block_count));
    }
    printf("time: %f \n", time);
    printf("Given block_size %zu (%f MB), our program can read block_count: %zu in %f seconds \n", block_size, (block_size / 1024.0 / 1024.0), block_count, time);
    printf("File size read %zu bytes (%f GB) \n", block_size * block_count, (block_size * block_count / (1024.0 * 1024.0 * 1024.0)));
    printf("Reading speed is: %f Mib/s \n", (block_size * block_count) / (1024.0 * 1024.0 * time));

    // printf("Block Size: %zu        Block Count: %zu \n", block_size, block_count);

    exit(0);
}
