#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent * entry;
    struct stat statbuf;
    if(NULL == (dp = opendir(dir)))
    {
        fprintf(stderr,"打不开文件夹： %s\n\r", dir);
        return;
    }
    chdir(dir);
    while (NULL != (entry = readdir(dp)))
    {
        lstat(entry->d_name,&statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
            if (strcmp(".",entry->d_name) == 0 || 
                strcmp("..",entry->d_name) == 0)
            {
                continue;
            }
            printf("%*s%s/\n\r",depth," ",entry->d_name);
            printdir(entry->d_name,depth + 4);            
        }
        else printf("%*s%s/\n\r",depth," ",entry->d_name);
        
    }
    chdir("..");
    closedir(dp);    
}
int main(int argc, char * argv[])
{
    char * topdir = ".";
    if(argc >= 2)
    {
        topdir = argv[1];
    }
    printf("Dir scan of %s\n\r",topdir);
    printf(topdir,0);
    printf("done!\n\r");
    return 0;
}