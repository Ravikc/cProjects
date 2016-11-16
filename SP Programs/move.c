#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Provide only 2 arguments\n");
        return 1;
    }
    link(argv[1], argv[2]);
    unlink(argv[1]);
    return 0;
}
