#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char** argv)
{
    pid_t pid = fork();
    if(pid == 0)//子进程
    {
        printf("1fd 0:%s\n",ttyname(0));
        printf("1fd 1:%s\n",ttyname(1));
        printf("1fd 2:%s\n",ttyname(2));
    }
    if(pid > 0)//父进程
    {
        printf("2fd 0:%s\n",ttyname(0));
        printf("2fd 1:%s\n",ttyname(1));
        printf("2fd 2:%s\n",ttyname(2));
    }
    getchar();
    return 0;
}