#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/un.h>
int main()
{
    int s_sockfd;
    int c_sockfd;
    int s_len, c_len;
    struct sockaddr_un s_address;
    struct sockaddr_un c_address;
    unlink("server_socket");
    s_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    s_address.sun_family = AF_UNIX;
    strcpy(s_address.sun_path, "server_socket");
    s_len = sizeof(s_address);
    bind(s_sockfd, (struct sockaddr *)&s_address, s_len);
    /*创建一个连接队列，开始等待客户进行连接*/
    listen(s_sockfd, 5);
    while (1)
    {
        char ch;
        printf("server waiting\n\r");
        c_len = sizeof(c_address);
        c_sockfd = accept(s_sockfd, (struct sockaddr *)&c_address, &c_len);
        read(c_sockfd, &ch, 1);
        ch++;
        write(c_sockfd, &ch, 1);
        close(c_sockfd);

    }
    
}