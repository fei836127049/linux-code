#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
{
    FILE * read_fp;
    char buffer[BUFSIZ + 1];
    int chars_read = 0;
    memset(buffer, '\0',sizeof(buffer));
    read_fp = popen("uname -a","r");
    if (read_fp != NULL)
    {
        chars_read = fread(buffer,sizeof(char), BUFSIZ, read_fp);
        if(chars_read > 0)
        {
            printf("Out put was: -\n%s\n\r",buffer);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}