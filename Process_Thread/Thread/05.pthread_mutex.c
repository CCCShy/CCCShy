#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>

#define MAX 50

//创建全局变量
int num;


pthread_mutex_t mutex;

void *func_A(void *arg)
{   

    for(int i = 0; i < MAX; i++)
    {
        // 上锁
        pthread_mutex_lock(&mutex);
        int cur = num;
        cur++;
        usleep(10);
        num = cur;
        printf("Thread A id = %lu, num = %d\n",pthread_self(), num);
        // 解锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *func_B(void *arg)
{

    for(int i = 0; i < MAX; i++)
    {
        // 上锁
        pthread_mutex_lock(&mutex);
        int cur = num;
        cur++;
        usleep(10);
        num = cur;
        printf("Thread B id = %lu, num = %d\n",pthread_self(), num);
        // 解锁
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t p1, p2;

    //初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    //创建两个子线程
    pthread_create(&p1, NULL, func_A, NULL);
    pthread_create(&p2, NULL, func_B, NULL);

    //阻塞回收
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    // 释放互斥锁
    pthread_mutex_destroy(&mutex);

    return 0;
}
