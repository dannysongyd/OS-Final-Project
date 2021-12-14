
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
