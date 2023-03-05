#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "erproc.h"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("Invalid number of arguments\n");
		return -1;
	}
	int port = atoi(argv[1]);
	int server = Socket(AF_INET, SOCK_STREAM, 0);
	
    struct sockaddr_in adr = { 0 };
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port);

	Bind(server, (struct sockaddr *)&adr, sizeof(adr));
    Listen(server, 5);
    socklen_t adrlen = sizeof(adr);

    int fd = Accept(server, (struct sockaddr *)&adr, &adrlen);
	char buf[256];
	ssize_t nread = read(fd, buf, 256);
	if (nread == -1) {
		perror("read failed\n");
		exit(EXIT_FAILURE);
	}

    if (nread == 0) {
        printf("END OF FILE occured\n");
    }

    write(STDOUT_FILENO, buf, nread);
    write(fd, buf, nread);

    sleep(15);

    close(fd);
    close(server);

	return EXIT_SUCCESS;
}
