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
    int s = alarm(5);
    printf("s = %d\n",s);
    sleep(2);
    printf("刚过2秒：%d\n",s);
    s = alarm(5);
    printf("s = %d\n",s);
    getchar();
    return 0;
}
