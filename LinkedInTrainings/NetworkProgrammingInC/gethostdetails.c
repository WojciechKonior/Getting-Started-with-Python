#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

int main()
{
    char host[BUFSIZ];
    int r;
    struct hostent *hostdata;
    char** addresses;
    r = gethostname(host, BUFSIZ);
    if(r==-1)
    {
        fprintf(stderr, "Unable to obtain host name\n");
        exit(1);
    }
    printf("The host is %s\n", host);

    hostdata = gethostbyname(host);
    if(hostdata == NULL)
    {
        fprintf(stderr, "Can't obtain hostdata\n");
        exit(1);
    }
    printf("Addresses: \n");
    addresses = hostdata->h_addr_list;
    while(*addresses)
    {
        printf("%s\n", inet_ntoa(*(struct in_addr *)*addresses));
        addresses++;
    }
    return 0;
}