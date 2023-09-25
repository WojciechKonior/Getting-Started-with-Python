#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
    struct addrinfo hints;
    struct addrinfo *server;

    int r;
    int sockfd;
    int clientfd;
    int option;

    struct sockaddr client_address;
    socklen_t client_len;

    const int buffer_size = 1024;
    char buffer[buffer_size];

    const char *http_data =
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n"
        "Content-Type: text/html\r\n\r\n"
        "<h1>Hello from your server!</h1>";

    // server configuration
    printf("Configuring server...");
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET6;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    r = getaddrinfo(0, "8080", &hints, &server);
    if (r != 0)
    {
        perror("failed");
        exit(1);
    }
    printf("done\n");

    // create socket
    printf("Assign a socket...");
    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1)
    {
        perror("failed");
        exit(1);
    }
    printf("done\n");

    // activate dual-stack configuration
    printf("Activating dual-stack configuration...");
    option = 0;
    r = setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&option, sizeof(option));
    if (r == -1)
    {
        perror("failed");
        exit(1);
    }
    printf("done\n");

    // binding a server to a socket
    printf("Binding server to a socket...");
    r = bind(sockfd, server->ai_addr, server->ai_addrlen);
    if (r == -1)
    {
        perror("failed");
        exit(1);
    }
    printf("done\n");

    // listen to incoming connections
    printf("Listening...");
    r = listen(sockfd, 1);
    if (r == -1)
    {
        perror("failed");
        exit(1);
    }
    printf("done\n");

    // accepting new connections
    printf("Accepting new connection ");
    client_len = sizeof(client_address);
    clientfd = accept(sockfd, &client_address, &client_len);
    if (client_len == -1)
    {
        perror("failed");
        exit(1);
    }
    printf("on file descriptor %d\n", clientfd);

    // client is now connected
    r = recv(clientfd, buffer, buffer_size, 0);
    if (r > 0)
    {
        printf("Received %d bytes\n---\n", r);
        for (int i = 0; i < r; i++)
            putchar(buffer[i]);
    }

    // send the response
    printf("Sending response...");
    r = send(clientfd, http_data, strlen(http_data), 0);
    if (r < 0)
    {
        perror("failed");
        exit(1);
    }
    printf("done\n");

    freeaddrinfo(server);
    close(sockfd);
    close(clientfd);
    return 0;
}