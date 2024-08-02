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

    //open 以写的方式打开有名管道(阻塞到对方以读的方式打开)
    int fd = open("myfifo",O_WRONLY);
    if(fd < 0)
    {
        perror("open");
        _exit(-1);
    }
    
    printf("写端open成功了\n");

    // 循环写入数据
    while(1)
    {
        // 获取键盘输入
        char buf[128] = "";
        printf("请输入要写入的数据：");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf) - 1] = 0;//清空换行符

        //发送数据
        write(fd,buf,strlen(buf));
        
        //退出循环
        if(strcmp(buf,"quit") == 0)
            break;
    }

    close(fd);
    return 0;
}
