#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

struct Test
{
    int num;
    int age;
};

// 子线程处理代码
void *callback(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        printf("子进程：i = %d\n",i);
    }
    printf("子进程：%ld\n",pthread_self());
    struct Test *t = (struct Test*)arg;
    t->age = 24;
    t->num = 100;
    pthread_exit(t);
}

int main(int argc, char const *argv[])
{
    struct Test t;
    //创建一个子线程
    pthread_t tid;
    pthread_create(&tid, NULL, callback, &t);

    //主线程代码
    void *ptr;
    pthread_join(tid, &ptr);
    struct Test *tmp = (struct Test*)ptr;
    printf("num = %d , age = %d\n",tmp->num, tmp->age);

    // 防止主线程结束回收虚拟空间导致子线程无法执行
    return 0;
}
