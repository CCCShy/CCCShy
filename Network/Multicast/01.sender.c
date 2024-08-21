/* UDP demo usage: */ 
// ./client serv_ip serv_port

#include"udp.h"

void usage(char const *s)
{
    printf("\nThis is a Multicast demo!\n");
    printf("\nUsage:%s serv_ip serv_port", s);
    printf("\n\t serv_ip:udp sender ip address(between 224~239 segment)");
    printf("\n\t serv_port:udp server port(>5000)\n\n");
}

int main(int argc, char const *argv[])
{
    int fd = -1;
    struct sockaddr_in sin;
    unsigned short port;

    port = atoi(argv[2]);
    if(port < 5000)
    {
        usage(argv[0]);
        exit(-1);
    }

    if(argc != 3)
    {
        usage(argv[0]);
        exit(-1);
    }

    //1.创建socket fd
    if((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)//UDP
    {
        perror("socket");
        exit(-1);
    }

    //2.填充struct sockaddr_in
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    if(inet_pton(AF_INET, argv[1], (void *)&sin.sin_addr.s_addr) != 1)
    {
        perror("inet_pton");
        exit(-1);
    }
    printf("Multicast starting...OK!\n");

    //3.写数据
    char buf[BUFSIZE];
    while(1)
    {
        bzero(buf , BUFSIZE);
        printf("Please input the string to server:");
        if(fgets(buf, BUFSIZE, stdin) == NULL)
        {
            perror("fgets");
            continue;
        }
        if(sendto(fd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&sin, sizeof(sin)) < 0)
        {
            perror("sendto");
            break;
        }
        if(!strncasecmp(buf, QUIT_STR, strlen(QUIT_STR)))
        {
            printf("sender is exiting!\n");
            break;
        }
    }
    close(fd);
    return 0;
}
