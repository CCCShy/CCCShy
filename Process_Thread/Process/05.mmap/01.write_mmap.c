#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>
int main(int argc, char const *argv[])
{
    //通过open事先打开文件
    int fd = open("tmp", O_RDWR | O_CREAT, 0666);
    if(fd < 0)
    {
        perror("open");
        _exit(-1);
    }

    //拓展文件大小
    truncate("tmp", 16);

    //建立映射
    char *buf = (char *)mmap(NULL, 16, PROT_READ | PROT_WRITE, MAP_SHARED, fd , 0);

    //使用区域
    strcpy(buf, "hello mmap");

    //断开映射
    munmap(buf, 16);
    return 0;
}
