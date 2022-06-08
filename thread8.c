#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define NUM_THREAD 6

void *thread_function(void *arg)
{
    int my_number = *(int *)arg;
    int rand_num = 0;
    printf("thread_function is running ! Argument was %d\n\r",my_number);
    rand_num = 1 + (int)(9.0 * rand()/(RAND_MAX + 1.0));
    sleep(rand_num);
    printf("Bye from %d\n\r",my_number);
    pthread_exit("thank you!\n\r");
}

int main()
{
    int res = 0;
    pthread_t thread_t[NUM_THREAD];
    void * thread_result;
    for (int i = 0; i < NUM_THREAD; i++)
    {
        res = pthread_create(&(thread_t[i]), NULL, thread_function,(void *)&i);
        if(res != 0)
        {
            printf("pthread create failed!\n\r");
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }
    for (int i = NUM_THREAD - 1; i >= 0; i--)
    {
        res = pthread_join(thread_t[i], &thread_result);
        if(res == 0)
        {
            printf("pthread join sucess!\n\r");
        }
        else
        {
            printf("pthread join failed!\n\r");
        }
    }
    printf("ALL Done!\n\r");
    exit(EXIT_SUCCESS);
}