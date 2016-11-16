#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/types.h>

void Execute(char *command)
{
    pid_t pid;
    char *arguments[3];
    int i = 0;
    bool hasSpace = false;


    arguments[2] = NULL;
    while(command[i] != '\0')
    {
        if(command[i] == (char)32)
            hasSpace = true;
            i++;    
    }

    if(hasSpace == true)
    {
    arguments[0] = strtok(command, " ");
    arguments[1] = strtok(NULL, " ");
    }

    else
    {
        arguments[0] = command;
        arguments[1] = NULL;
    }

    //printf("arguments are %s and %s", arguments[0], arguments[1]);  

    if((pid = fork()) < 0) 
    {
        printf("Fork unsuccessful\n");
        return;
    }

     else if(pid > 0)
    {
        printf("Inside parent\nWaiting for child to execute\n");
        wait(&i);
        printf("Child has finished executing\n");
    }

    else
    {
       printf("Inisde child\n");
        execvp(arguments[0],  arguments);
        _exit(0);
    }
    
}


int main(void)
{
    char command[10];
    while(1)
    {
        memset(command, 0, sizeof(command));
        printf("_Jok3r__ >> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';
        if(!strcmp(command, "exit"))
            return 0;
        Execute(command);
    }
}
