#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *thread1(void *arg)
{
    int j = 0;
    //未进行系统调用，不会被杀死
    for(int i = 0; i < 3; i++)
    {
        j++;
    }
    printf("j = %d\n",j);
    printf("子线程ID：%ld\n",pthread_self());
    //需要加延迟，否则还未杀死子线程，子线程已执行结束
    sleep(1);
    for(int i = 0; i < 10; i++)
    {
        printf("子线程：i = %d\n",i);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    //创建子线程
    pthread_create(&tid, NULL, thread1, NULL);
    printf("子线程创建成功，子线程ID为：%ld\n",tid);


    // 主线程
    printf("主线程ID：%ld\n",pthread_self());
    for(int i = 0; i < 3; i++)
    {
        printf("主线程：i = %d\n",i);
    }

    // 主线程和子线程分离
    pthread_detach(tid);

    //取消子线程
    int i;
    i = pthread_cancel(tid);
    printf("错误代码：%d\n",i);
    // 主线程退出
    pthread_exit(NULL);
    return 0;
}
