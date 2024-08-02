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
        execlp("ls","ls","-a","-l","-h",NULL);  
        _exit(-1);
    }
    else if(pid > 0)//父进程
    {
        for(int i = 0;i<5;i++)
        {
            printf("父进程%d中的num = %d\n",getpid(),i);
            sleep(1);
        }
    }
    return 0;
}