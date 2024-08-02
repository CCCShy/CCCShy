#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char const *argv[])
{
    int fd = dup(1);
    printf("fd=%d\n",fd);
    printf("hello dup\n");
    write(fd,"hello dup hehe\n",strlen("hello dup hehe"));
    close(fd);
    return 0;
}
