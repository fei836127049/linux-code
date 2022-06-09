#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
sem_t bin_sem;

void *thread_function(void *arg)
{
    sem_wait(&bin_sem);
    while (strncmp("end", work_area,3) != 0)
    {
        printf("you input %d characters\n\r",strlen(work_area) - 1);
        sem_wait(&bin_sem);
    }
    pthread_exit("thank you!\n\r");
}

int main()
{
    int res = 0;
    pthread_t thread_t;
    void * thread_result;
    res = sem_init(&bin_sem, 0, 0);
    if (res != 0)
    {
        printf("sem init failed!\n\r");
        exit(EXIT_FAILURE);
    }
    
    res = pthread_create(&thread_t, NULL, thread_function,NULL);
    if(res != 0)
    {
        printf("pthread create failed!\n\r");
        exit(EXIT_FAILURE);
    }
    printf("input some text,enter 'end' to finish!\n\r");
    while (strncmp("end", work_area,3) != 0)
    {
        fgets(work_area, WORK_SIZE, stdin);
        sem_post(&bin_sem);
    }
    printf("waiting for thread to finish!\n\r");
    res = pthread_join(thread_t, &thread_result);
    if(res != 0)
    {
        printf("pthread join failed!\n\r");
        exit(EXIT_FAILURE);
    }
    printf("thread joined! it retruned %s\n\r",(char*)thread_result);
    sem_destroy(&bin_sem);
    exit(EXIT_SUCCESS);
}