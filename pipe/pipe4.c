#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int data_processed = 0;
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    int file_descriptor = 0;\
    memset(buffer,'\0',sizeof(buffer));
    sscanf(argv[1],"%d",&file_descriptor);
    data_processed = read(file_descriptor,buffer,BUFSIZ);
    printf("%d -read %d byte\n\r",getpid(),data_processed,buffer);
    exit(EXIT_SUCCESS);
}