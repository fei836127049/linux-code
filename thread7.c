#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

char message[] = "hello world!";

void *thread_function(void *arg)
{
    int res = 0;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    if(res != 0)
    {
        printf("pthread_setcancelstate failed!\n\r");
        exit(EXIT_FAILURE);
    }
    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
    if(res != 0)
    {
        printf("pthread_setcanceltype failed!\n\r");
        exit(EXIT_FAILURE);
    }
    printf("thread_function is running !\n\r");
    for (int i = 0; i < 10; i++)
    {
        /* code */
        printf("thread is still running(%d)\n\r",i);
        sleep(1);
    }
    pthread_exit("thank you!\n\r");
}

int main()
{
    int res = 0;
    pthread_t thread_t;
    void * thread_result;
    res = pthread_create(&thread_t, NULL, thread_function,NULL);
    if(res != 0)
    {
        printf("pthread create failed!\n\r");
        exit(EXIT_FAILURE);
    }
    /*主线程休眠5秒后，然后发送一个取消请求*/
    sleep(5);
    printf("canceling thread!\n\r");
    res = pthread_cancel(thread_t);
    if(res != 0)
    {
        printf("pthread_cancel failed!\n\r");
        exit(EXIT_FAILURE);
    }
    printf("waiting for thread to finish!\n\r");
    res = pthread_join(thread_t, &thread_result);
    if(res != 0)
    {
        printf("pthread join failed!\n\r");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}