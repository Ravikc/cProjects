#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<fcntl.h>


void EchoBack(void)
{
    char buffer[50];
  //  read(1, buffer, sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);   //fgets allows redirection ,read doesnt.
    write(1, buffer,strlen(buffer));
    return;
}

void ShowContents(char *argv[])
{
    char buffer[50];
    int fp = open(argv[1], O_RDONLY);
    read(fp, buffer, sizeof(buffer));
    write(1, buffer, strlen(buffer));
    close(fp);
}

void Concatenate(char *argv[])
{
    char buffer[50];
    int fd = open(argv[1], O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    write(1, buffer, strlen(buffer));
    close(fd);
    memset(buffer, 0, sizeof(buffer));
    fd = open(argv[2], O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    write(1, buffer, strlen(buffer));
    close(fd);
    return;
}

int main(int argc, char *argv[])
{
    switch(argc)
    {
        case 1: EchoBack();
            break;
        case 2: ShowContents(argv);
            break;
        case 3: Concatenate(argv);
            break;
    }
    return 0;
}