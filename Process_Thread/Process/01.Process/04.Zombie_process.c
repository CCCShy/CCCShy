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
        //在子进程中修改num的值
        printf("子进程pid:%d 父进程号：%d\n",getpid(),getppid());
        //显示结束
        exit(-1);
    }
    else if(pid > 0)//父进程
    {
        printf("父进程pid:%d\n",getpid());
        while(1);
    }
    return 0;
}