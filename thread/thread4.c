#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define WORK_SIZE 1024
/*声明一个工作区*/
char work_area[WORK_SIZE];
pthread_mutex_t work_sem;
int time_to_exit = 0;

void *thread_function(void *arg)
{
    sleep(1);
    pthread_mutex_lock(&work_sem);
    while (strncmp("end", work_area,3) != 0)
    {
        printf("you input %d characters\n\r",strlen(work_area) - 1);
        work_area[0] = '\0';
        pthread_mutex_unlock(&work_sem);
        sleep(1);
        pthread_mutex_lock(&work_sem);
        while (work_area[0] == '\0')
        {
            pthread_mutex_unlock(&work_sem);
            sleep(1);
            pthread_mutex_lock(&work_sem);
        }
        
    }
    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_sem);
    pthread_exit("thank you!\n\r");
}

int main()
{
    int res = 0;
    pthread_t thread_t;
    void * thread_result;
    res = pthread_mutex_init(&work_sem, NULL);
    if (res != 0)
    {
        printf("pthread mutex init failed!\n\r");
        exit(EXIT_FAILURE);
    }
    
    res = pthread_create(&thread_t, NULL, thread_function,NULL);
    if(res != 0)
    {
        printf("pthread create failed!\n\r");
        exit(EXIT_FAILURE);
    }
    /*加锁*/
    pthread_mutex_lock(&work_sem);
    printf("input some text,enter 'end' to finish!\n\r");
    while (!time_to_exit)
    {
        fgets(work_area, WORK_SIZE, stdin);
        /*解锁*/
        pthread_mutex_unlock(&work_sem);
        while (1)
        {
            pthread_mutex_lock(&work_sem);
            if(work_area[0] != '\0')
            {
                pthread_mutex_unlock(&work_sem);
                sleep(1);
            }
            else
            {
                break;
            }
        }
        
    }
    pthread_mutex_unlock(&work_sem);
    printf("waiting for thread to finish!\n\r");
    res = pthread_join(thread_t, &thread_result);
    if(res != 0)
    {
        printf("pthread join failed!\n\r");
        exit(EXIT_FAILURE);
    }
    printf("thread joined! it retruned %s\n\r",(char*)thread_result);
    pthread_mutex_destroy(&work_sem);
    exit(EXIT_SUCCESS);
}