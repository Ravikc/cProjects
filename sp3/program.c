#include<stdio.h>
#include<string.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 

void noArguments(void);
void showContentsOnly(char *);
void concatenate(char *, char *);
char buffer[20];

int main(int argc, char *argv[])
{
    if(argc == 1)
        noArguments();
    if(argc == 2)
        showContentsOnly(argv[1]);
    else
        concatenate(argv[1], argv[2]);
        
    return 0;
}

void noArguments()
{
    read(1, buffer, 20);
    write(1, buffer, sizeof(buffer));
}

void showContentsOnly(char *fileName)
{
    int fd;
    char tempBuffer[20];
    fd = open(fileName, O_RDONLY);
    read(fd, tempBuffer, 80);
    close(fd);
    write(1, tempBuffer, strlen(tempBuffer));
}

void concatenate(char *firstFile, char *secondFile)
{
    char commonBuffer[50];
    int fd;
    //writing first file
    fd = open(firstFile, O_RDONLY); 
    read(fd, commonBuffer, sizeof(commonBuffer));
    close(fd);
    write(1, commonBuffer, strlen(commonBuffer));

    memset(commonBuffer, 0, sizeof(commonBuffer));
    //writing second file
    fd = open(secondFile, O_RDONLY);
    read(fd, commonBuffer, sizeof(commonBuffer));
    close(fd);
    write(1, commonBuffer, strlen(commonBuffer));
}