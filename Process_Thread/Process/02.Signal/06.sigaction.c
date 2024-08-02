#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>

void my_func(int sig)
{
    printf("ctrl+c被按下了\n");
}

int main(int argc, char const *argv[])
{
    struct sigaction act;
    //act存放回调函数
    act.sa_handler = my_func;
    //act添加阻塞集 act.sa_mask
    sigemptyset(&act.sa_mask);
    //SA_RESETHAND:信号处理之后重新设置为默认的处理方式
    act.sa_flags = 0;//默认方式
    //act.sa_flags |= SA_RESETHAND

    sigaction(SIGINT,&act,NULL);
    while(1);
    return 0;
}
