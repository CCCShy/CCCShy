#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>

pthread_cond_t cond;
pthread_mutex_t mutex;

//链表的节点类型
struct Node
{
    int number;
    struct Node *next;
};

// 创建头结点
struct Node *Head = NULL;

void *producer(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        // 创建新节点
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        // 初始化节点
        newNode->number = rand() % 1000;
        newNode->next = Head;
        Head = newNode;
        printf("生产者ID:%ld   number=%d\n",pthread_self(),newNode->number);
        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
        sleep(rand() % 3);
    }
    return NULL;
}

// 消费者
void *consumer(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(Head == NULL)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        int num;
        struct Node *tmp = Head;
        num = Head->number;
        Head = Head->next;
        printf("消费者ID:%ld   number=%d\n",pthread_self(),num);
        free(tmp);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t p1[5], p2[5];

    //初始化
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    //创建5个生产者，5个消费者
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&p1[i], NULL, producer, NULL);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&p2[i], NULL, consumer, NULL);
    }

    //阻塞回收
    for(int i = 0; i < 5; i++)
    {
        pthread_join(p1[i], NULL);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_join(p2[i], NULL);
    }

    // 释放
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
