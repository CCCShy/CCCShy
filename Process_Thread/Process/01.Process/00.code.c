#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
    pid_t pid = getpid();
    printf("当前进程的ID：%d\n",pid);
    printf("父进程的ID：%d\n",getppid());
    printf("当前进程组的ID：%d\n",getpgid(0));
    getchar();
    return 0;
}