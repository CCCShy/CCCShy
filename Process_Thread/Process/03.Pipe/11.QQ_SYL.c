#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    //创建两个管道
    mkfifo("SYL_to_HJR",0666);
    mkfifo("HJR_to_SYL",0666);

    // 创建2个子进程
    int i = 0;
    for(i = 0;i < 2;i++)
    {
        pid_t pid = fork();
        if(pid == 0)
            break;
    }

    if(i == 0)//子进程1  负责发送消息
    {
        int fd = open("SYL_to_HJR",O_WRONLY);
        if(fd < 0)
        {
            perror("open");
            _exit(-1);
        }

        //获取键盘输入
        while(1)
        {
            char buf[128] = "";
            printf("SYL：");
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1] = 0;

            //发送数据
            write(fd,buf,strlen(buf));

            //退出循环
            if(strcmp(buf,"bye") == 0)
                break;
        }
        close(fd);
        _exit(-1);
    }

    else if(i == 1)//子进程2  负责接受消息
    {
        int fd = open("HJR_to_SYL",O_RDONLY);
        if(fd < 0)
        {
            perror("open");
            _exit(-1);
        }
        while(1)
        {
            char buf[128] = "";
            //读取数据
            read(fd,buf,sizeof(buf));
            printf("\rHJR：%s\nSYL：",buf);
            fflush(stdout);
            //退出循环
            if(strcmp(buf,"bye") == 0)
                break;
        }
        close(fd);
        _exit(-1);
    }
    else if(i == 2)//父进程  负责回收子进程资源
    {
        while(1)
        {
            pid_t pid = waitpid(-1, NULL, WNOHANG);
            if(pid > 0)//可省略
            {
                printf("子进程%d已退出\n",pid);
            }
            // else if(pid == 0)//可省略
            //     continue;
            if(pid == -1)
                break;
        }
    }
    return 0;
}
