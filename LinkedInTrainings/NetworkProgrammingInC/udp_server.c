#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
    struct addrinfo hints;
    struct addrinfo *server;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    puts("Getting addrinfo...");
    int r = getaddrinfo(0, "8080", &hints, &server);
    if(r!=0){perror("Failed"); return 1;}

    puts("Setting up server socket...");
    int serv_socket = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if(serv_socket==-1){perror("Failed"); return 1;}

    puts("Binding...");
    struct sockaddr client_addr;
    socklen_t client_addrlen = sizeof(struct sockaddr);
    int r2 = bind(serv_socket, &client_addr, client_addrlen);
    if(r2==-1){perror("Failed"); return 1;}

    // puts("Listening...");
    // int r3 = listen(serv_socket, 1);
    // int client_socket = accept(serv_socket, &client_addr, &client_addrlen);
    // if(client_socket==-1) {perror("Failed"); return 1;}


    freeaddrinfo(server);
    close(serv_socket);
    // close(client_socket);
    return 0;
}

// netdb.h
// struct addrinfo
// ai_family
// ai_socktype
// AF_INET
// SOCK_STREAM
// getaddrinfo
// freeaddrinfo