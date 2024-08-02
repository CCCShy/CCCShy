#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char** argv)
{
    pid_t pid = fork();
    if(pid > 0)
    {
        _exit(-1);//父进程结束
    }
    //子进程设置会话
    setsid();
    
    //改变工作目录
    chdir("/");

    //设置权限掩码
    umask(0002);

    //关闭文件描述符
    close(0);
    close(1);
    close(2);

    printf("进程ID：%d\n",getpid());
    //守护进程核心任务
    while(1)
    {
        // 核心任务
    }
    
    return 0;
}