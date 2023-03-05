#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "erproc.h"

void argument_comline(char *argv[], char *ip_addr, int *port_addr)
{
    *port_addr = atoi(argv[1]);
    strcpy(ip_addr, argv[2]);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
		perror("Invalid number of arguments");
		exit(EXIT_FAILURE);
	}

    int port_addr;
    char *ip_addr = malloc(sizeof(char) * (strlen(argv[2]) + 1));
    argument_comline(argv, ip_addr, &port_addr);

	int fd = Socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in adr = { 0 };
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port_addr);
	Inet_pton(AF_INET, ip_addr, &adr.sin_addr);
	Connect(fd, (struct sockaddr *)&adr, sizeof(adr));
	write(fd, "Text\n", sizeof("Text\n"));

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
