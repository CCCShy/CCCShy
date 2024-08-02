#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

// 子线程处理代码
void *callback(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        printf("子进程：i = %d\n",i);
    }
    printf("子进程：%ld\n",pthread_self());
}

int main(int argc, char const *argv[])
{
    //创建一个子线程
    pthread_t tid;
    pthread_create(&tid, NULL, callback, NULL);

    //主线程代码
    for(int i = 0; i < 5; i++)
    {
        printf("主线程：i = %d\n",i);
    }
    printf("主线程：%ld\n",pthread_self());
    pthread_exit(NULL);

    // 防止主线程结束回收虚拟空间导致子线程无法执行
    // sleep(3);
    return 0;
}
