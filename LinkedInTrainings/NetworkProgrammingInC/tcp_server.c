#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    struct addrinfo hints, *server;
    struct sockaddr client_address;
    socklen_t client_len;
    int r, sockfd, clientfd;
    const int buffer_size = 1024;
    char buffer[buffer_size];

    printf("Configureing server...");
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    r = getaddrinfo(0, "8080", &hints, &server);
    if(r!=0) {perror("failed");exit(1);}
    puts(" done");

    printf("Assign a socket...");
    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if(sockfd==-1){perror("failed"); exit(1);}
    puts(" done");

    printf("Binding socket...");
    r = bind(sockfd, server->ai_addr, server->ai_addrlen);
    if(r==-1){perror("failed"); exit(1);}
    puts(" done");

    printf("Listening...");
    r = listen(sockfd,1);
    if(r==-1){perror("failed"); exit(1);}
    puts(" done");

    printf("Accepting new connection ");
    client_len = sizeof(client_address);
    clientfd = accept(sockfd, &client_address, &client_len);
    if(clientfd==-1){perror("failed"); exit(1);}
    printf("on file descriptor %d\n", clientfd);

    r = recv(clientfd, buffer, buffer_size, 0);
    if(r>0){
        printf("Received %d bytes:\n---\n", r);
        for(int i = 0; i<r; i++)
            putchar(buffer[i]);
    }

    const char *http_data = 
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n"
        "Content-Type: text/html\r\n\r\n"
        "<h1>Hello from your server!</h1>";

    r = send(clientfd, http_data, strlen(http_data), 0);
    if(r<1){perror("send failed"); exit(1);}
    printf("Sent %d bytes\n", r);

    close(clientfd);
    freeaddrinfo(server);
    close(sockfd);

    return 0;
}