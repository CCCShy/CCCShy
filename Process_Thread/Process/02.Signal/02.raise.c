#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    printf("5s后进程结束\n");
    sleep(5);
    raise(SIGINT);
    printf("------------%d---------------\n",i);
    return 0;
}
