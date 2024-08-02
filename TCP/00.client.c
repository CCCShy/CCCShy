#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(int argc, char const *argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    //1.创建通信套接字
    if(fd == -1)
    {
        perror("socket");
        exit(-1);
    }

    //2.连接服务器 IP、port
    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(40000);
    inet_pton(AF_INET, "192.168.0.6", (void *)&saddr.sin_addr.s_addr);
    int ret = connect(fd, (struct sockaddr *)&saddr, sizeof(saddr));
    if(ret == -1)
    {
        perror("connect");
        exit(-1);
    }

    //3.通信
    int number = 0;
    while(1)
    {
        //发送数据
        char buff[1024];
        //fgets(buff, sizeof(buff) - 1, stdin);
        sprintf(buff, "hello, world, %d...\n",number++);
        send(fd, buff, strlen(buff) + 1, 0); 
        
        //接收数据
        memset(buff, 0, sizeof(buff));
        int len = recv(fd, buff, sizeof(buff), 0);
        if(len > 0)
        {
            printf("service say：%s\n",buff);
        }
        else if(len == 0)
        {
            printf("服务器已经断开了连接...\n");
            break;
        }
        else
        {
            perror("recv");
            break;
        }
        sleep(1);
    }

    //4.关闭文件描述符
    close(fd);

    return 0;
}
