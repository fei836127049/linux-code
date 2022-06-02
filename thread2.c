#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

char message[] = "hello world!";
int run_now = 1;

void *thread_function(void *arg)
{
    int n = 0;
    printf("thread_function is running ! Argument was %s\n\r",(char *)arg);
    while (n++ < 20)
    {
        if(run_now == 2)
        {
            printf("2\n\r");
            run_now = 1;
        }
        else
        {
            sleep(1);
        }
    }
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit("thank you!\n\r");
}

int main()
{
    int res = 0;
    int n = 0;
    pthread_t thread_t;
    void * thread_result;
    res = pthread_create(&thread_t, NULL, thread_function,(void *)message);
    while (n++ < 20)
    {
        if(run_now == 1)
        {
            printf("1\n\r");
            run_now = 2;
        }
        else
        {
            sleep(1);
        }
    }
    
    if(res != 0)
    {
        printf("pthread create failed!\n\r");
        exit(EXIT_FAILURE);
    }
    printf("waiting for thread to finish!\n\r");
    res = pthread_join(thread_t, &thread_result);
    if(res != 0)
    {
        printf("pthread join failed!\n\r");
        exit(EXIT_FAILURE);
    }
    printf("thread joined! it retruned %s\n\r",(char*)thread_result);
    printf("message is new %s\n\r",message);
    exit(EXIT_SUCCESS);
}