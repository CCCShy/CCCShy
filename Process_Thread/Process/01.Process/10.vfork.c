#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char** argv)
{
    //vfork创建子进程
    pid_t pid = vfork();
    if(pid == 0)//子进程
    {
        for(int i = 0;i < 5;i++)
        {
            printf("子进程ID：%d中的i=%d\n",getpid(),i);
            sleep(1);
        }
        // 显示退出
        _exit(-1);
    }
    else if(pid > 0)//父进程
    {
        for(int i = 0;i < 5;i++)
        {
            printf("父进程ID：%d中的i=%d\n",getpid(),i);
            sleep(1);
        }
    }
    return 0;
}