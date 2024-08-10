#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    fd_set rset;       
    int maxfd = -1;
    int fd;
    struct timeval tout;

    fd = socket();
    bind(fd,...);
    listen(fd,...);
    
    while(1)
    {
        maxfd = fd;
        FD_ZERO(&rset);
        FD_SET(fd, &rset);//依次把已经建立好连接fd加入集合中，记录下最大的文件描述符maxfd
        //...加入fd进rset
        //...FIXME！
#if 0
        select(maxfd + 1, &rset, NULL, NULL, NULL);
#else
        tout.tv_sec = 5;
        tout.tv_usec = 0;
        select(maxfd + 1, &rset, NULL, NULL, &tout);
#endif
        if(FD_ISSET(fd, &rset))
        {
            newfd = accept(fd, ...);
        }

        //依次判断已建立连接的客户端是否有数据
        //...FIXME！
    }
    return 0;
}
