#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/stat.h>

// function to get the file size
off_t getFileSize(char *filename)
{
    int fd;
    struct stat buf;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    fstat(fd, &buf);
    off_t size = buf.st_size;
    return size;
}

void readUtil(char *filename, size_t block_size)
{
    int fd;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    unsigned int *buf = malloc(block_size);
    ssize_t read_size;
    unsigned int xor = 0;
    // read
    while ((read_size = read(fd, buf, block_size)) > 0)
    {
        // xor
        ssize_t numOfIntSize = read_size / sizeof(int);
        for (ssize_t j = 0; j < numOfIntSize; j++)
        {
            xor ^= buf[j];
        }
    }

    // print xor
    printf("xor is %08x \n", xor);

    // free
    free(buf);
    close(fd);
}
double countTime(char *filename, size_t block_size)
{

    // timer start time
    clock_t begin;
    clock_t end;
    double time_spend;

    begin = clock();
    readUtil(filename, block_size);
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

    block_size = 262144;
    // block_count = (2.625154495244 * 1024.0 * 1024.0 * 1024.0) / block_size;

    off_t fileSize = getFileSize(filename);
    block_count = fileSize / block_size;

    printf("The best block_size we tested is %zu bytes \n", block_size);
    printf("Reading given file %s with file size %lld(%f GB) \n", filename, fileSize, (fileSize / 1024.0 / 1024.0 / 1024.0));
    printf("\n");

    printf("Raw performance \n");
    runningTime = countTime(filename, block_size);
    printf("Reading speed is: %f Mib/s \n", (block_size * block_count) / (1024.0 * 1024.0 * runningTime));
    printf("\n");

    printf("Cached performance \n");
    runningTime = countTime(filename, block_size);
    printf("Reading speed is: %f Mib/s \n", (block_size * block_count) / (1024.0 * 1024.0 * runningTime));

    exit(0);
}
