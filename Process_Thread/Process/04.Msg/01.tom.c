#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

typedef struct Mymsg
{
    long mtype;
    char mtext[64];
    char mname[32];
}MSG;

int main(int argc, char const *argv[])
{
    //获取IPC唯一的key值
    key_t key = ftok("/",2021);
    printf("key = %#X\n",key);

    //创建消息队列
    int msqid = msgget(key,IPC_CREAT | 0666);
    printf("msqid=%d\n",msqid);

    //接收消息
    MSG msg;
    memset(&msg, 0, sizeof(msg));
    msgrcv(msqid, &msg, sizeof(msg) - sizeof(long), 30, 0);
    printf("发送者：%s\n",msg.mname);
    printf("消息内容：%s\n",msg.mtext);

    return 0;
}
