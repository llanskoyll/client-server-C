#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "erproc.h"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("Invalid number of arguments");
		exit(EXIT_FAILURE);
	}

	int port = atoi(argv[1]);

	int fd = Socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in adr = { 0 };
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port);
	Inet_pton(AF_INET, "192.168.1.138", &adr.sin_addr);
	Connect(fd, (struct sockaddr *)&adr, sizeof(adr));
	write(fd, "You'r pidor\n", sizeof("You'r pidor\n"));

    char buf[256];
    ssize_t nread;
    nread = read(fd, buf, 256);
    if (nread == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    if (nread == 0) {
        printf("EOF occured\n");
    }
    write(STDOUT_FILENO, buf, nread);
    sleep(10);
    close(fd);

	return EXIT_SUCCESS;
}