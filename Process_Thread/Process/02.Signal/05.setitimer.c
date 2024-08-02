#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

void my_fun(int sig)
{
    printf("触发信号sig = %d\n",sig);
}

int main(int argc, char const *argv[])
{
    struct itimerval tv;
    //设置一次运行所需要的时间
    tv.it_value.tv_sec = 5;
    tv.it_value.tv_usec = 0;
    //设置周期执行时间
    tv.it_interval.tv_sec = 2;
    tv.it_interval.tv_usec = 0;
    //注册信号的自定义函数
    signal(SIGALRM,my_fun);
    setitimer(ITIMER_REAL, &tv, NULL);
    getchar();
    return(0);
}
