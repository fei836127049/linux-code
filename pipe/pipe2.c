#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
{
    int data_processed = 0;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;
    memset(buffer,'\0',sizeof(buffer));
    /*pipe管道调用成功*/
    if(0 == pipe(file_pipes))
    {
        fork_result = fork();//成功返回0，失败返回-1
        if (-1 == fork_result)
        {
            fprintf(stderr,"fork failed!\n\r");
            exit(EXIT_FAILURE);
        }
        /*处于子进程：子进程读*/
        if (0 == fork_result)
        {
            data_processed = read(file_pipes[0],buffer,BUFSIZ);
            printf("read %d byte: %s\n\r",data_processed,buffer);
            exit(EXIT_SUCCESS);
        }
        /*处于父进程：父进程写*/
        else
        {
            data_processed = write(file_pipes[1],some_data,strlen(some_data));
            printf("wrote %d byte: %s\n\r",data_processed,buffer);
        }
              
    }
    exit(EXIT_SUCCESS);
}