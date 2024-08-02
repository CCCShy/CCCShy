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

    //发送消息
    MSG msg;
    memset(&msg, 0, sizeof(msg));
    msg.mtype = 20;
    strcpy(msg.mname,"bob");
    strcpy(msg.mtext,"hello msg");
    msgsnd(msqid, &msg, sizeof(MSG) - sizeof(long), 0);
    return 0;
}
