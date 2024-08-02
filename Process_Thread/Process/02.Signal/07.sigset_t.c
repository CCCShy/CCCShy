#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    //定义一个信号集合
    sigset_t set;

    // 清空信号集合
    sigemptyset(&set);

    // 将SIGINT加入set集合
    sigaddset(&set,SIGINT);

    //将SIGTSTP加入set集合
    sigaddset(&set,SIGTSTP);

    //判断SIGINT是否加入set集合
    if(sigismember(&set,SIGINT))
        printf("SIGNIT已加入集合\n");
    return 0;
}