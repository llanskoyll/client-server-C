#include "erproc.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int Socket(int domain, int type, int protocol)
{
	int ret = socket(domain, type, protocol); 
	if (ret == -1) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	return ret;
}

int Accept(int sockfd, struct sockaddr *addr,
            socklen_t *addrlen)
{
    int ret = accept(sockfd, addr, addrlen);
    if (ret == -1) {
        perror("failed accept");
        exit(EXIT_FAILURE);
    }

    return ret;
}

void Inet_pton(int af, const char *src, void *dst)
{
    int ret = inet_pton(af, src, dst);
    if (ret == 0) {
        printf("inet_pton failed: src does not contain a character"
            " string representing a valid network address in the specified"
            " address family\n");
        exit(EXIT_FAILURE);
    }
    if (ret == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret = connect(sockfd, addr, addrlen);
    if (ret == -1) {
        perror("Connect failed");
        exit(EXIT_SUCCESS);
    }
}
