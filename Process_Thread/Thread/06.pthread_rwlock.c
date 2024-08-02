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


pthread_rwlock_t rwlock;

void *Func_write(void *arg)
{   

    for(int i = 0; i < MAX; i++)
    {
        // 上锁
        pthread_rwlock_wrlock(&rwlock);
        int cur = num;
        cur++;
        num = cur;
        printf("Thread write id = %lu, num = %d\n",pthread_self(), num);
        // 解锁
        pthread_rwlock_unlock(&rwlock);
        usleep(rand() % 100);
    }
    return NULL;
}

void *Func_read(void *arg)
{

    for(int i = 0; i < MAX; i++)
    {
        // 上锁
        pthread_rwlock_rdlock(&rwlock);
        printf("Thread read id = %lu, num = %d\n",pthread_self(), num);
        // 解锁
        pthread_rwlock_unlock(&rwlock);
        usleep(rand() % 100);
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t p1[5], p2[3];

    //初始化互斥锁
    pthread_rwlock_init(&rwlock, NULL);

    //创建3个写进程，5个读进程
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&p1[i], NULL, Func_read, NULL);
    }
    for(int i = 0; i < 3; i++)
    {
        pthread_create(&p2[i], NULL, Func_write, NULL);
    }
    //阻塞回收
    for(int i = 0; i < 5; i++)
    {
        pthread_join(p1[i], NULL);
    }
    for(int i = 0; i < 3; i++)
    {
        pthread_join(p2[i], NULL);
    }
    // 释放互斥锁
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
