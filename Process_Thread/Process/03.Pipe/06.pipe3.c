// 案例2：读端关闭，写进程退出
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
        int i = 0;
        //子进程接受父进程消息
        while(1)
        {
            printf("子进程：%d等待获取消息\n",getpid());
            unsigned char bf[128] = "";
            read(fd[0],bf,sizeof(bf));
            printf("子进程：%d成功获取消息：%s\n",getpid(),bf);
            if(++i == 3)
                break;
        }  
        close(fd[0]);
        // 显示退出
        _exit(-1);
    }

    else if(pid > 0)//父进程
    {
        //父进程的读端无意义（可以提前关闭）
        close(fd[0]);

        
        //写端写入数据
        while(1)
        {
            printf("父进程：%d将写入以下信息：\n",getpid());
            sleep(1);
            write(fd[1],"hello pipe",strlen("hello pipe"));
            printf("父进程：%d写入完成\n",getpid());
        }
        
        // 通信完毕 应该关闭写端
        close(fd[1]);

        // 等待子进程退出
        wait(NULL);
    }

    return 0;
}
