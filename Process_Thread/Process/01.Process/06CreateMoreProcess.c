#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#define N 3

int main(int argc, char** argv)
{
    int i;
    for(i = 0;i < N;i++)
    {
        pid_t pid = fork();
        if(pid == 0)//防止子进程创建孙进程
            break;
    }
    //判断具体的进程
    if(i == 0)//子进程1
    {
        //完成任务A
        int j = 5;
        for(;j>0;j--)
        {
            printf("子进程%d 剩余时间%ds\n",getpid(),j);
            sleep(1);
        }
        _exit(-1);
    }
    else if(i == 1)//子进程2
    {
        //完成任务B
        int j = 3;
        for(;j>0;j--)
        {
            printf("子进程%d 剩余时间%ds\n",getpid(),j);
            sleep(1);
        }
        _exit(-1);
    }
    else if(i == 2)//子进程3
    {
        //完成任务C
        int j = 8;
        for(;j>0;j--)
        {
            printf("子进程%d 剩余时间%ds\n",getpid(),j);
            sleep(1);
        }
        _exit(-1);
    }
    else if(i == N)//父进程
    {
        //回收所有子进程资源
        while(1)
        {
            pid_t pid = waitpid(-1,NULL,WNOHANG);//不阻塞
            if(pid > 0)
            {
                printf("子进程%d退出了\n",pid);
            }
            else if(pid == 0)
                continue;
            else if(pid == -1)
            {
                break;
            }
        }
    }
    return 0;
}