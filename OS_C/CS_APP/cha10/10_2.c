#include "csapp.h"

int main()
{
    int fd1, fd2;
    char c, d;

    fd1 = open("foobar.txt", O_RDONLY, 0);
    fd2 = open("foobar.txt", O_RDONLY, 0);
    read(fd1, &c, 1);
    read(fd2, &c, 1);
    read(fd1, &d, 1);
    printf("c = %c\n", c);
    printf("d = %c\n", d);
    exit(0);
}
