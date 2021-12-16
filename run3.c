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

    unsigned int *buf = malloc(block_size);

    // read
    for (int i = 0; i < block_count; i++)
    {
        ssize_t read_size = read(fd, buf, block_size);

        if (read_size < 0)
        {
            perror("r3");
            exit(1);
        }
        ssize_t numOfIntSize = read_size / sizeof(int);
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

    return (double)(end - begin) / CLOCKS_PER_SEC;
}

// * ./run <filename> [-r|-w] <block_size> <block_count>
int main(int argc, char *argv[])
{

    char *filename;
    size_t block_size;
    size_t block_count;
    int fd;
    double runningTime;

    filename = argv[1];

    sscanf(argv[2], "%lu", &block_size);
    sscanf(argv[3], "%lu", &block_count);

    // readUtil(filename, block_size, block_count);
    runningTime = countTime(filename, block_size, block_count);
    printf("Given block_size %zu (%f MB), our program can read block_count: %zu in %f seconds \n", block_size, (block_size / 1024.0 / 1024.0), block_count, runningTime);
    printf("File size read %zu bytes (%f GB) \n", block_size * block_count, (block_size * block_count / (1024.0 * 1024.0 * 1024.0)));
    printf("Reading speed is: %f Mib/s \n", (block_size * block_count) / (1024.0 * 1024.0 * runningTime));

    exit(0);
}
