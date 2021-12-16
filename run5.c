#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <math.h>

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

double countLseekTime(char *filename, size_t block_count)
{

    // timer start time
    clock_t begin;
    clock_t end;
    double time_spend;
    int fd;

    begin = clock();
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    // using lseek to read the file
    for (int i = 0; i < block_count; i++)
    {
        lseek(fd, 0, SEEK_CUR);
    }

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

    // sscanf(argv[2], "%lu", &block_size);
    block_size = 1.0;
    sscanf(argv[2], "%lu", &block_count);

    // readUtil(filename, block_size, block_count);
    runningTime = countTime(filename, block_size, block_count);
    printf("read() Time is %f \n", runningTime);
    printf("Reading speed is: %f Mib/s \n", (block_size * block_count) / (1024.0 * 1024.0 * runningTime));
    printf("Reading speed is: %f B/s \n", (block_size * block_count) / (runningTime));

    printf("\n");

    runningTime = countLseekTime(filename, block_count);
    printf("lseek() Time is %f \n", runningTime);
    printf("Reading speed is: %f Mib/s \n", (block_size * block_count) / (1024.0 * 1024.0 * runningTime));
    printf("Reading speed is: %f B/s \n", (block_size * block_count) / (runningTime));

    exit(0);
}
