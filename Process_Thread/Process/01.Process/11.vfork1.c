#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char** argv)
{
    int num = 10;
    //vfork创建子进程
    pid_t pid = vfork();
    if(pid == 0)//子进程
    {
        // 显示退出
        num = 1000;
        _exit(-1);
    }
    else if(pid > 0)//父进程
    {
        printf("父进程中的num = %d\n",num);
    }
    return 0;
}