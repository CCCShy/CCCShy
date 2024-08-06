#include"pthread_tcp.h"

void cli_data_handle(void *arg);

int main(int argc, char const *argv[])
{
    int fd;
    struct sockaddr_in sin;
    //1.创建Socket fd
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(-1);
    }

    //优化4：允许绑定地址快速重用
    int b_reuse = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));

    // 2.绑定
    // 填充struct sockaddr_in结构体变量
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(10000);//网络字节序的端口号
    // 优化1：让服务器能绑定在任意的IP上
#if 1
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    //sin.sin_addr.s_addr = inet_addr(SERV_IP_ADDR);//支持IPV4
#else
    if(inet_pton(AF_INET, SERV_IP_ADDR, (void *)&sin.sin_addr) != 1)
    {
        perror("inet_pton");
        exit(-1);
    }
#endif
    if(bind(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("bind");
        exit(-1);
    }

    // 3.调用listen()把主动套接字变成被动套接字
    if(listen(fd, 5) < 0)
    {
        perror("listen");
        exit(-1);
    }
    printf("Server starting...OK!\n");

    // 4.accept()函数阻塞等待客户端连接请求
    int newfd = -1;
//优化3：用多进程/多线程处理已经建立好连接的客户端数据
 //优化2：通过程序获取刚建立连接的socket的客户端的IP地址和端口号
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    pthread_t tid; 

    // 创建线程
    while(1)
    {
        newfd = accept(fd, (struct sockaddr *)&cin, &addrlen);
        if(newfd == -1)
        {
            perror("accept");
            exit(-1);
        }

        char ipv4_addr[16];
        if(NULL == inet_ntop(AF_INET, (void *)&cin.sin_addr, ipv4_addr, sizeof(cin)))
        {
            perror("inet_ntop");
            exit(-1);
        }
        printf("Client(%s:%d) is connected!\n",ipv4_addr, ntohs(cin.sin_port));
        pthread_create(&tid, NULL, (void *)cli_data_handle, (void *)&newfd);
        pthread_detach(tid);
    }

    close(fd);
    return 0;
}


void cli_data_handle(void *arg)
{
    int newfd = *(int *)arg;
    printf("handler thread：newfd = %d\n", newfd);
        // 5.读写
    char buf[BUFSIZE];
    int ret = -1;
    while(1)
    {
        bzero(buf, BUFSIZE);
        do
        {
            ret = read(newfd, buf, BUFSIZE);
        } while (ret < 0 && EINTR == errno);
        if(ret < 0)
        {
            perror("read");
            exit(-1);
        }
        if(ret == 0)
        {
            break;
        }
        printf("Receive Data:%s", buf);
        if(strncasecmp(buf, QUIT_STR,strlen(QUIT_STR)) == 0)//用户输入了quit字符
        {
            printf("Client(fd=%d) is exiting!\n", newfd);
            break;
        }
    }
    close(newfd);
    pthread_exit(NULL);
    return;
}