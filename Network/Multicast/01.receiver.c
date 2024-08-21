#include"udp.h"

int main(int argc, char const *argv[])
{
    int fd = -1;
    struct sockaddr_in sin;

    //1.创建socket fd
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0)//UDP
    {
        perror("socket");
        exit(-1);
    }

    //2.优化：允许绑定地址快速重用
    int b_reuse = 1;               
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));

    //加入多播组
    struct ip_mreq mreq;
    bzero(&mreq, sizeof(mreq));
    mreq.imr_multiaddr.s_addr = inet_addr(MULTICAST_IP);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    setsockopt(fd, IPPROTO_IP, IP_ADDR_MEMBERSHIP, &mreq, sizeof(mreq));

    //3.绑定
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERV_PORT);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("bind");
        exit(-1);
    }

    printf("UDP Server starting...OK!\n");

    //4.接收数据
    char buf[BUFSIZE];
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    while(1)
    {
        bzero(buf , BUFSIZE);
        if(recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&cin, &addrlen) < 0)
        {
            perror("recvfrom");
            break;
        }
        char ipv4_addr[16];
        if(!inet_ntop(AF_INET, &cin.sin_addr.s_addr, ipv4_addr, sizeof(cin)))
        {
            perror("inet_ntop");
            break;
        }
        printf("Receive from(%s:%d) Data:%s", ipv4_addr, ntohs(cin.sin_port), buf);
        if(!strncasecmp(buf, QUIT_STR, strlen(QUIT_STR)))
        {
            printf("Client(%s:%d) is exiting!\n", ipv4_addr, ntohs(cin.sin_port));
        }
    }
    close(fd);
    return 0;
}
