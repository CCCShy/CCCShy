#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char **argv)
{
    int num = 10;
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
        num = 10000;
        while(1)
        {
            printf("子进程pid:%d中num=%d\n",getpid(),num);
            sleep(1);
        }
    }
    else if(pid > 0)//父进程
    {
        while(1)
        {
            printf("父进程pid:%d中num=%d\n",getpid(),num);
            sleep(1);
        }
    }
    getchar();
    return 0;
}