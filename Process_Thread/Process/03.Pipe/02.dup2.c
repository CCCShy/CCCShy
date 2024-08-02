#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char const *argv[])
{
    //复制文件描述符1
    dup2(1,4);
    //输出字符串
    printf("hello dup\n");
    write(4,"hello dup hehe\n",strlen("hello dup hehe"));
    close(4);
    return 0;
}
