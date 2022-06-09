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
    memset(buffer,'\0',sizeof(buffer));
    if(0 == pipe(file_pipes))
    {
        data_processed = write(file_pipes[1],some_data,strlen(some_data));
        printf("wrote %d byte: %s\n\r",data_processed,buffer);
        // data_processed = read(file_pipes[1],buffer,BUFSIZ);
        // printf("read %d byte: %s\n\r",data_processed,buffer);
        data_processed = read(file_pipes[0],buffer,BUFSIZ);
        printf("read %d byte: %s\n\r",data_processed,buffer);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}