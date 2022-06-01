#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
static int alarm_fired = 0;
void ding(int sig)
{
    alarm_fired = 1;
}
int main()
{
    pid_t pid;
    printf("alarm application starting!\n\r");
    /*创建一个新进程*/
    pid = fork();
    switch (pid)
    {
    case /* constant-expression */-1:
        /* code */
        perror("fork failed!\n\r");
        exit(1);
    case 0:
        sleep(5);
        kill(getppid(),SIGALRM);
        exit(0);
    }
    printf("waiting 5 second!\n\r");
    (void) signal(SIGALRM, ding);
    pause();
    if(alarm_fired)
    {
        printf("ding\n\r"); 
    }
    
    printf("Done!\n\r");
    exit(0);
}