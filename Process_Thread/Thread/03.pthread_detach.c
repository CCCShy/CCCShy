#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

// 子线程处理代码
void *callback(void *arg)
{
    printf("子线程：%ld\n",pthread_self());
    for(int i = 0; i < 5; i++)
    {
        printf("子线程：i = %d\n",i);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    //创建一个子线程
    pthread_t tid;
    pthread_create(&tid, NULL, callback, NULL);

    //主线程代码
    printf("主线程：%ld\n",pthread_self());
    for(int i = 0; i < 5; i++)
    {
        printf("主线程：i = %d\n",i);
    }

    //子线程与主线程分离
    pthread_detach(tid);
    // 主线程退出
    pthread_exit(NULL);
    return 0;
}
