#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define WORK_SIZE 1024
char message[] = "hello world!";
int thread_finish = 0;

void *thread_function(void *arg)
{
    printf("thread_function is running ! Argument was %s\n\r",(char *)arg);
    sleep(4);
    printf("second thread setting finished flag,and exiting now!\n\r");
    thread_finish = 1;
    pthread_exit("thank you!\n\r");
}

int main()
{
    int res = 0;
    pthread_t thread_t;
    pthread_attr_t thread_attr;
    res = pthread_attr_init(&thread_attr);
    if (res != 0)
    {
        printf("pthread attr init failed!\n\r");
        exit(EXIT_FAILURE);
    }
    res = pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);
    if (res != 0)
    {
        printf("pthread_attr_setdetachstate failed!\n\r");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&thread_t, &thread_attr, thread_function,(void *)message);
    if(res != 0)
    {
        printf("pthread create failed!\n\r");
        exit(EXIT_FAILURE);
    }
    (void)pthread_attr_destroy(&thread_attr);
    while (!thread_finish)
    {
        printf("Waiting for thread to finished!\n\r");
        sleep(1);
    }
    printf("Other thread finished!\n\r");
    exit(EXIT_SUCCESS);
}