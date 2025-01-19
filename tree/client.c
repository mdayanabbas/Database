#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "Ws2_32.lib")

static void die(const char *msg) {
    int err = WSAGetLastError();
    fprintf(stderr, "[%d] %s\n", err, msg);
    WSACleanup();  
    abort();
}

int main() {
    WSADATA wsaData;
    SOCKET fd = INVALID_SOCKET;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        die("WSAStartup()");
    }

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == INVALID_SOCKET) {
        die("socket()");
    }

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);  
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); 

    int rv = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (rv == SOCKET_ERROR) {
        die("connect()");
    }

    char msg[] = "hello";
    send(fd, msg, strlen(msg), 0);

    char rbuf[64] = {};
    int n = recv(fd, rbuf, sizeof(rbuf) - 1, 0);
    if (n == SOCKET_ERROR) {
        die("recv()");
    }

    printf("server says: %s\n", rbuf);


    closesocket(fd);

    WSACleanup();
    return 0;
}
