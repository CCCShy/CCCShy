#ifndef __MAKEU_NET_H__
#define __MAKEU_NET_H__
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<strings.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<errno.h>
#include <arpa/inet.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>

#define SERV_PORT 5001
#define SERV_IP_ADDR "127.0.0.1"
#define BUFSIZE 64
#define QUIT_STR "quit"

#endif