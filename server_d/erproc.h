#pragma once

#include <sys/types.h>
#include <sys/socket.h>

int Socket(int domain, int type, int protocol);
void Bind(int socketfd, const struct sockaddr *addr, socklen_t addrlen);
void Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
