#pragma once

#include <sys/types.h>
#include <sys/socket.h>

int Socket(int domain, int type, int protocol);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void Inet_pton(int af, const char *src, void *dst);
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
