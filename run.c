#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

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
        for (ssize_t j = 0; j < numOfIntSize; j++)
        {
            xor ^= buf[j];
        }

        // printf("%zu \n", read_size); // DELETE
    }

    // free
    free(buf);

    //print xor
    printf("xor is %08x \n", xor);

    close(fd);
}

unsigned int xorbuf(unsigned int *buffer, int size)
{
    unsigned int result = 0;
    for (int i = 0; i < size; i++)
    {
        result ^= buffer[i];
    }
    return result;
}

// * ./run <filename> [-r|-w] <block_size> <block_count>
int main(int argc, char *argv[])
{
    // print size of usigned long
    // printf("sizeof(unsigned long) = %lu\n", sizeof(unsigned long));

    char *filename;
    char *mode;
    size_t block_size;
    size_t block_count;
    int fd;

    filename = argv[1];
    mode = argv[2];

    sscanf(argv[3], "%lu", &block_size);
    sscanf(argv[4], "%lu", &block_count);

    // printf("%s \n", filename); // DELETE
    // printf("%s \n", mode); // DELETE
    // printf("%lu \n", block_size); // DELETE
    // printf("%lu \n", block_count); // DELETE
    // printf("\n");

    // char buf[block_size];

    if (strcmp(mode, "-r") == 0)
    {
        readUtil(filename, block_size, block_count);
    }
    else if (strcmp(mode, "-w") == 0)
    {
        fd = open(filename, O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
        if (fd < 0)
        {
            perror("r1");
            exit(1);
        }

        unsigned int *buf = malloc(block_size);

        for (int i = 0; i < block_count; i++)
        {
            ssize_t write_size = write(fd, buf, block_size);
            if (write_size < 0)
            {
                perror("r3");
                exit(1);
            }

            printf("%zu \n", write_size); // DELETE
        }

        free(buf);

        close(fd);
    }
    else
    {
        printf("%s\n", "Invalid argument");
    }

    exit(0);
}
