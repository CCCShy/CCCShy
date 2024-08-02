#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(pid == 0)//子进程
    {
        while(1)
        {
            printf("子进程%d---------玩游戏-------\n",getpid());
            sleep(1);
        }
        _exit(-1);
    }
    else if(pid > 0)//父进程
    {
        printf("5s时间 去补作业\n");
        sleep(5);
        kill(pid,SIGKILL);
        wait(NULL);
    }
    return 0;
}
