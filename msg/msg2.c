#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>

#define MAX_TEXT 512
struct msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int running = 1;
    int msgid;
    struct msg_st some_data;
    long int msg_to_receive = 0;
    char buffer[BUFSIZ];
    /*建立消息队列*/
    msgid = msgget((key_t)1234,0666 | IPC_CREAT);
    if(msgid == -1)
    {
        fprintf(stderr, "msgget failed with error: %d\n\r", errno);
        exit(EXIT_FAILURE);
    }
    while (running)
    {
        printf("Enter some text: ");
        fgets(buffer, BUFSIZ, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, buffer);
        if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msgsnd failed\n\r");
            exit(EXIT_FAILURE);
        }
        if(strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
        if(msgrcv(msgid, (void *)&some_data, 
        BUFSIZ,msg_to_receive, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed with error: %d\n\r", errno);
            exit(EXIT_FAILURE);
        }
        printf("you wrote: %s", some_data.some_text);
        if(strncmp(some_data.some_text, "end", 3) == 0)
        {
            running = 0;
        }
    }
    exit(EXIT_SUCCESS);
    
}
