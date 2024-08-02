#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    //获取唯一key值
    key_t key = ftok("/",2024);

    //获取共享内存的标识符（分配物理内存）
    int shmid = shmget(key, 128, IPC_CREAT | 0666);

    //将虚拟内存和物理内存建立映射
    char *shmaddr = (char *)shmat(shmid, NULL, 0);

    //操作虚拟内存
    printf("%s\n",shmaddr);

    //释放映射
    shmdt(shmaddr);

    return 0;
}
