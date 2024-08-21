#include"select.h"

void cli_data_handle(void *arg);

void sig_child_handle(int signo)
{
    if(SIGCHLD == signo)
    {
        waitpid(-1, NULL, WNOHANG);
    }
}

int main(int argc, char const *argv[])
{
    int fd;
    struct sockaddr_un sun;
    signal(SIGCHLD, sig_child_handle);
    //1.创建Socket fd
    if((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)//基于本地的TCP通信
    {
        perror("socket");
        exit(-1);
    }

    //允许绑定地址快速重用
    int b_reuse = 1;               
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));

    // 2.绑定
    // 填充struct sockaddr_un结构体变量
    bzero(&sun,sizeof(sun));
    sun.sun_family = AF_UNIX;
    
    //如果UNIX_DOMAIN_FILE所指向的文件存在，则删除
    if(access(UNIX_DOMAIN_FILE, F_OK) == 0)
    {
        unlink(UNIX_DOMAIN_FILE);//删除文件函数
    }
    strncpy(sun.sun_path, UNIX_DOMAIN_FILE, strlen(UNIX_DOMAIN_FILE));


    if(bind(fd, (struct sockaddr *)&sun, sizeof(sun)) < 0)
    {
        perror("bind");
        exit(-1);
    }

    // 3.调用listen()把主动套接字变成被动套接字
    if(listen(fd, 5) < 0)
    {
        perror("listen");
        exit(-1);
    }
    printf("UNIX domain starting...OK!\n");

    // 4.accept()函数阻塞等待客户端连接请求
    int newfd = -1;

    while (1)
    {
        newfd = accept(fd, NULL, NULL);
        if(newfd == -1)
        {
            perror("accept");
            exit(-1);
        }
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork");
            exit(-1);
        }
        if(pid == 0)//子进程
        {
            close(fd);
            printf("Client is connected!\n");
            cli_data_handle(&newfd);
            return 0;
        }
        else//父进程
        {
            close(newfd);
        }
    }
    
    close(fd);
    return 0;
}

void cli_data_handle(void *arg)
{
    int newfd = *(int *)arg;
    printf("Child handler process：newfd = %d\n", newfd);
        // 5.读写
    char buf[BUFSIZE];
    char resp_buf[BUFSIZE + 10];
    int ret = -1;
    while(1)
    {
        bzero(buf, BUFSIZE);
        do
        {
            ret = read(newfd, buf, BUFSIZE);
        } while (ret < 0 && EINTR == errno);
        if(ret < 0)
        {
            perror("read");
            exit(-1);
        }
        if(ret == 0)
        {
            break;
        }
        printf("Receive Data:%s", buf);

        bzero(resp_buf, BUFSIZE + 10);
        strncpy(resp_buf, SERV_RESP_STR, strlen(SERV_RESP_STR));
        strcat(resp_buf, buf);
        do
        {
            ret = write(newfd, resp_buf, strlen(resp_buf));
        } while (ret < 0 && EINTR == errno);
        
        if(strncasecmp(buf, QUIT_STR,strlen(QUIT_STR)) == 0)//用户输入了quit字符
        {
            printf("Client(fd=%d) is exiting!\n", newfd);
            break;
        }
    }
    close(newfd);
    pthread_exit(NULL);
    return;
}