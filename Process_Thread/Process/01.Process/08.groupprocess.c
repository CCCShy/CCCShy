#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char** argv)
{
    pid_t pid = fork();
    if(pid == 0)//子进程
    {
        printf("子进程：%d\n",getpid());
    }
    else if(pid > 0)
    {
        printf("父进程：%d\n",getpid());
    }
    getchar();
    return 0;
}