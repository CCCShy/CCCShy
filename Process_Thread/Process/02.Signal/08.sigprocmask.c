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

    //将set集合添加到阻塞集
    sigprocmask(SIG_BLOCK,&set,NULL);

    printf("5s后SIGINT将从阻塞集中删除\n");
    sleep(5);

    //将set集合从阻塞集中删除
    sigprocmask(SIG_UNBLOCK,&set,NULL);
    getchar();

    return 0;
}