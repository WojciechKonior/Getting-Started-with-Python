// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <netdb.h>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <netinet/in.h>

// int main()
// {
//     int r, sockfd;
//     struct addrinfo hints, *host;
//     const int buffer_size = 1024;
//     char buffer[buffer_size];

//     memset(&hints, 0, sizeof(struct addrinfo));
//     hints.ai_family = AF_INET;
//     hints.ai_socktype = SOCK_STREAM;

//     r = getaddrinfo("time.nist.gov", "daytime", &hints, &host);
//     if(r!=0){perror("client fault"); exit(1);}

//     sockfd = socket(
//         host->ai_family,
//         host->ai_socktype,
//         host->ai_protocol
//     );
//     if(sockfd==-1){perror("client code"); exit(1);}

//     r = connect(sockfd, host->ai_addr, host->ai_addrlen);
//     if(r==-1){perror("client code"); exit(1);}

//     r = read(sockfd, buffer, buffer_size);
//     buffer[r] = '\0';

//     printf("The buffer is: \n%s\n", buffer);

//     freeaddrinfo(host);
//     close(sockfd);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    struct addrinfo hints;
    struct addrinfo *host;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int r = getaddrinfo(0, "8080", &hints, &host);
    if(r!=0){perror("failed-1"); exit(1);}

    int sockfd = socket(host->ai_family, host->ai_socktype, host->ai_protocol);
    if(sockfd==-1) {perror("failed0"); exit(1);}

    r = connect(sockfd, host->ai_addr, host->ai_addrlen);
    if(r==-1){perror("failed1");exit(1);}

    const char* buffer = "hello server from TCP";
    r = send(sockfd, buffer, strlen(buffer), 0);
    if(r==-1){perror("failed2");exit(1);}

    const int buffer_size = 1024;
    char *buffer2[buffer_size];
    r = recv(sockfd, buffer2, buffer_size, 0);
    buffer2[r] = '\0';
    printf("Received buffer of size %d bytes is:\n%s", r, buffer2);

    close(sockfd);
    freeaddrinfo(host);

    printf("done\n");
    return 0;
}
