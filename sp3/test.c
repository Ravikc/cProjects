#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("Argc: %d\n", argc);
   // printf("Agrv1: %s", argv[1]);
    for(i = 0; i < argc; i++)
        printf("Argv %d: %s\n", i, argv[i]);
    return 0;
}