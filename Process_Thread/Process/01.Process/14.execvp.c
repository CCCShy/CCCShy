#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char** argv)
{
    printf("执行ls命令前\n");
    // execl("/bin/ls","ls","-a","-l","-h",NULL);
    // execlp("ls","ls","-a","-l","-h",NULL);
    char* avg[] = {"-a","-l","-h",NULL};
    execvp("ls",avg);
    printf("执行ls命令后\n");
    return 0;
}