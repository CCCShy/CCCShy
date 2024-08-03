#include"process_tcp.h"

void usage(char *s)
{
    printf("\n%s serv_ip serv_port", s);
    printf("\n\t serv_ip:server ip address");
    printf("\n\t serv_port:server port(>5000)\n\n");
}

int main(int argc, char *argv[])
{
    int fd;
    struct sockaddr_in sin;
    short port;

    if(argc != 3)
    {
        usage(argv[0]);
        exit(-1);
    }

    //1.创建Socket fd
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(-1);
    }

    port = atoi(argv[2]);
    if(port < 5000)
    {
        usage(argv[0]);
        exit(-1);
    }

    //2.connect()连接服务器
    // 填充struct sockaddr_in结构体变量
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
#if 0
    sin.sin_addr.s_addr = inet_addr(SERV_IP_ADDR);
#else
    if(inet_pton(AF_INET, argv[1], (void *)&sin.sin_addr.s_addr) != 1)
    {
        perror("inet_pton");
        exit(-1);
    }
#endif
    if(connect(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("connect");
        exit(-1);
    }

    // 3.读写(写数据)
    char buf[BUFSIZE];
    int ret = -1;
    while(1)
    {
        bzero(buf, BUFSIZE);
        if(fgets(buf, BUFSIZE-1, stdin) == NULL)
        {
            perror("fgets");
            continue;
        }
        write(fd, buf, strlen(buf));
        if(strncasecmp(buf, QUIT_STR,strlen(QUIT_STR)) == 0)//用户输入了quit字符
        {
            printf("Client is exiting!\n");
            break;
        }
    }

    // 4.关闭套接字
    close(fd);
    return 0;
}
