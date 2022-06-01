#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void ouch(int sig)
{
    printf("OUCH - I got signal %d\r\n", sig);
    (void) signal(SIGINT,SIG_DFL);
}
int main()
{
    (void) signal(SIGINT,ouch);
    while (1)
    {
        /* code */
        printf("Hello World!\r\n");
        sleep(1);
    }
    
}