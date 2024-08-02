// 无名管道综合案例：ps -A | grep bash
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    //创建无名管道
    int fd[2];
    pipe(fd);

    int i = 0;
    //创建两个子进程
    for(i = 0;i < 2;i++)
    {
        pid_t pid = fork();
        if(pid == 0)
            break;
    }

    if(i == 0)//子进程1
    {
        //ps -A
        //读端无意义
        close(fd[0]);
        //1要作为fd[1]的副本
        dup2(fd[1],1);
        //执行ps -A
        execlp("ps","ps","-A",NULL);
        _exit(-1);
    }

    else if(i == 1)//子进程2
    {
        //grep bash
        //写端无意义
        close(fd[1]);
        //0要作为fd[0]的副本
        dup2(fd[0],0);
        execlp("grep","grep","bash",NULL);
        _exit(-1);
    }

    else if(i == 2)//父进程
    {
        //关闭管道读写端
        close(fd[0]);
        close(fd[1]);
        while(1)
        {
            pid_t pid = waitpid(-1,NULL,WNOHANG);
            if(pid > 0)
            {
                printf("子进程%d退出了\n",pid);
            }
            else if(pid == 0)
            {
                continue;
            }
            else if(pid == -1)
                break;
        }
    }

    return 0;
}
