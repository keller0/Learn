#include "csapp.h"

int main(int argc, char **argv)
{
    int n;
    rio_t rio;
    char buf[MAXBUF];

	if (argv = 2) {
		int fd = open(argv[1], O_RDONLY, 0);
		while ((n = Rio_readn(fd, buf, MAXBUF)) != 0)
			Rio_writen(STDOUT_FILENO, buf, n);
		exit(EXIT_SUCCESS);	
	}

    rio_readinitb(&rio, STDIN_FILENO);
    while((n = Rio_readlineb(&rio, buf, MAXBUF)) != 0)
        Rio_writen(STDOUT_FILENO, buf, n);
	exit(EXIT_SUCCESS);
}
