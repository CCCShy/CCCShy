#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char **argv)
{
    //创建子进程
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("创建失败\n");
        return 0;
    }
    else if(pid == 0)//子进程
    {
        printf("子进程pid:%d\n",getpid());
    }
    else if(pid > 0)//父进程
    {
        printf("父进程pid:%d\n",getpid());
    }
    getchar();
    return 0;
}