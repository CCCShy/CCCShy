#include"select.h"

void usage(char *s)
{
    printf("\n%s serv_name serv_port", s);
    printf("\n\t serv_name:server ip address");
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
    printf("Client Starting...OK!\n");


    fd_set rset;
    int maxfd = -1;
    struct timeval tout;
    int ret = -1;
    char buf[BUFSIZ];
    while(1)
    {
        FD_ZERO(&rset);
        FD_SET(0, &rset);
        FD_SET(fd, &rset);
        maxfd = fd;

        tout.tv_sec = 5;
        tout.tv_usec = 0;

        select(maxfd + 1, &rset, NULL, NULL, &tout);
        if(FD_ISSET(0, &rset))//标准键盘上有输入，读取键盘输入，发送到网络套接字fd
        {
            bzero(buf, BUFSIZ);
            do
            {
                ret = read(0, buf, BUFSIZ - 1);
            } while (ret < 0 && EINTR == errno);
            if(ret < 0)
            {
                perror("read");
                continue;
            }
            if(!ret)
                continue;;//服务器关闭
            if(write(fd, buf, strlen(buf)) < 0)
            {
                perror("write() to socket");
                continue;
            }
            if(strncasecmp(buf, QUIT_STR,strlen(QUIT_STR)) == 0)//用户输入了quit字符
            {
                printf("Client is exiting!\n");
                break;
            }
        }
        
        if(FD_ISSET(fd, &rset))//服务器发送过来了数据，读取套接字数据，处理
        {
            bzero(buf ,BUFSIZE);
            do
            {
                ret = read(fd, buf, BUFSIZ);
            } while (ret < 0 && EINTR == errno);
            if(ret < 0)
            {
                perror("read from socket");
                continue;
            }
            if(!ret)//服务器关闭
            {
                break;
            }
            printf("server said:%s\n", buf);

            //This is a BUG ,FIXME!!
            if((strlen(buf) > strlen(SERV_RESP_STR)) && ((buf + strlen(SERV_RESP_STR), QUIT_STR,strlen(QUIT_STR)) == 0))//用户输入了quit字符
            {
                printf("Sender Client is exiting!\n");
                break;
            }
        }
    }

    // 4.关闭套接字
    close(fd);
    return 0;
}
