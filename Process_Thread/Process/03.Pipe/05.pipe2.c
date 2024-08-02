// 案例1：调用write函数向管道里写数据，当缓冲区已满时write也会阻塞
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    pipe(fd);

    //创建子进程
    //父进程发 子进程收
    pid_t pid = fork();

    if(pid == 0)//子进程
    {
        //子进程的写端无意义（可以提前关闭）
        close(fd[1]);

        //子进程接受父进程消息
        getchar();
        close(fd[0]);

        // 显示退出
        _exit(-1);
    }

    else if(pid > 0)//父进程
    {
        //父进程的读端无意义（可以提前关闭）
        close(fd[0]);

        char bf1[128] = "";
        
        //写端写入数据
        for (int i = 0; i < 1000; i++)
        {
            write(fd[1],bf1,sizeof(bf1));
            printf("i = %d\n",i+1);
        }
        
        // 通信完毕 应该关闭写端
        close(fd[1]);

        // 等待子进程退出
        wait(NULL);
    }

    return 0;
}
