// 无名管道综合案例：ps -A | grep bash
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    //创建有名管道(保证两个进程识别相同目录)
    mkfifo("myfifo",0666);

    //open 以读的方式打开有名管道(阻塞到对方以写的方式打开)
    int fd = open("myfifo",O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        _exit(-1);
    }
    
    printf("读端open成功了\n");

    //循环的读取数据
    while(1)
    {
        //接收数据
        char buf[128] = "";
        read(fd,buf,sizeof(buf));
        printf("收到的数据为：%s\n",buf);

        // 退出循环
        if(strcmp("quit",buf) == 0)
            break;
    }

    close(fd);
    return 0;
}
