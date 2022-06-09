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
    read_fp = popen("cat popen*.c | wc -l","r");
    if (read_fp != NULL)
    {
        /*可以通过多次调用fread来获取更多的数据*/
        chars_read = fread(buffer,sizeof(char), BUFSIZ, read_fp);
        while(chars_read > 0)
        {
            buffer[chars_read - 1] = '\0';
            printf("reading %d: -\n%s\n\r",BUFSIZ,buffer);
            chars_read = fread(buffer,sizeof(char), BUFSIZ, read_fp);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}