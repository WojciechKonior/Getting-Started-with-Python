#include <stdio.h>
#include <string.h>
#include <netdb.h>

int main()
{
    const char* host = "yahoo.com";
    const char* port = "80";
    struct addrinfo hints;
    struct addrinfo *resources;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    int r = getaddrinfo(host, port, &hints, &resources);
    if(r!=0)
    {
        puts("Failed");
        return 1;
    }

    puts("Done");

    freeaddrinfo(resources);
    return 0;
}


//netdb.h
//struct addrinfo
//ai_family
//ai_socktype
//AF_INET
//SOCK_STREAM
//getaddrinfo
//freeaddrinfo