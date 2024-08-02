#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<pthread.h>

//信息结构体
struct SockInfo
{
    struct sockaddr_in addr;
    int fd;
};

struct SockInfo infos[512];

void* working(void *arg);


int main(int argc, char const *argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    //1.创建监听套接字
    if(fd == -1)
    {
        perror("socket");
        exit(-1);
    }

    //2.绑定本地的IP、port
    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(40000);
    saddr.sin_addr.s_addr = INADDR_ANY; //0 = 0.0.0.0
    int ret = bind(fd, (struct sockaddr *)&saddr, sizeof(saddr));
    if(ret == -1)
    {
        perror("bind");
        exit(-1);
    }

    //3.设置监听
    ret = listen(fd, 128);
    if(ret == -1)
    {
        perror("listen");
        exit(-1);
    }

    //初始化结构体数组
    int max = sizeof(infos) / sizeof(infos[0]);
    for(int i = 0; i < max; i++)
    {
        bzero(&infos[i], sizeof(infos[i]));
        infos[i].fd = -1;
    }

    //4.阻塞并等待连接
    struct sockaddr_in caddr;
    socklen_t addrlen = sizeof(caddr);
    while(1)
    {
        struct SockInfo *pinfo;
        for(int i = 0; i < max; i++)
        {
            if(infos[i].fd == -1)
            {
                pinfo = &infos[i];
                break;
            }
        }
        int cfd = accept(fd, (struct sockaddr *)&pinfo->addr, &addrlen);
        pinfo->fd = cfd;
        if(cfd == -1)
        {
            perror("accept");
            exit(-1);
        }

        //创建子线程
        pthread_t tid;
        pthread_create(&tid, NULL, working, pinfo);
        pthread_detach(tid);
    }
    close(fd);

    return 0;
}

void* working(void *arg)
{
    struct SockInfo *pinfo = (struct SockInfo *)arg;
    //5.连接建立成功， 打印客户端的IP和端口信息
    char ip[32];
    inet_ntop(AF_INET, (void *)&pinfo->addr.sin_addr.s_addr, ip, sizeof(ip));
    printf("客户端的IP：%s，端口：%d\n",ip, ntohs(pinfo->addr.sin_port));

    //6.通信
    while(1)
    {
        char buff[1024];
        memset(buff, 0, sizeof(buff));
        int len = recv(pinfo->fd, buff, sizeof(buff), 0);
        
        if(len > 0)
        {
            printf("client say：%s\n",buff);
            send(pinfo->fd, buff, len, 0);
        }
        else if(len == 0)
        {
            printf("客户端已经断开了连接...\n");
            break;
        }
        else
        {
            perror("recv");
            break;
        }
    }

    //7.关闭文件描述符
    close(pinfo->fd);
    pinfo->fd = -1;

    //线程退出
    pthread_exit(NULL);

    return NULL;
}
