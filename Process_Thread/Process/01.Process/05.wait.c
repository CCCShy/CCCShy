#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
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
        int i = 5;
        for(i = 5;i>0;i--)
        {
            printf("子进程pid:%d 剩余生命值%ds\n",getpid(),i);
            sleep(1);
        }
        printf("子进程pid:%d 结束了\n",getpid());
        //显示结束
        _exit(-1);
    }
    else if(pid > 0)//父进程
    {
        printf("父进程pid:%d 等待子进程结束\n",getpid());
        int status = 0;
        pid_t pid = wait(&status);
        if(WIFEXITED(status))//子进程正常退出
        {
            //输出状态值
            printf("子进程退出的状态值:%d\n",WEXITSTATUS(status));
        }
        printf("父进程pid:%d 子进程%d已结束\n",getpid(),pid);
    }
    return 0;
}