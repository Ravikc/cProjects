#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

char command[10];

void Execute()
{   
    char temp[10]; 
    char *arguments[3];
    bool hasSpace= false;
    int i =0;
    arguments[2] = NULL;

   
     command[strlen(command)-1] = '\0';
   
    
    
    while(command[i] != '\0')
    {
        if(command[i] == (char)32)
        {
               hasSpace = true;
               break;
        }
        i++;             
    }
    
    if(hasSpace)
    {
         arguments[0] = strtok(command, " ");
         arguments[1] = strtok(NULL, " ");
    }
    
   
    else
    {
        strcpy(arguments[0], command);
        arguments[1] = NULL;
    }
   
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Inside child\n");
        execvp(arguments[0], arguments);
        _exit(0);
    }   
    else if(pid > 0)
    {        
        wait(&i);
        printf("Inside Parent\n");
    } 
   
}

int main()
{    
    int i = 0,status = 1;

    while(status)
    {
        memset(command, 0, sizeof(command));
        printf(">>_Jok3r__>>");
        fgets(command, sizeof(command), stdin);    
        if(strcmp(command, "exit\n") != 0)
            Execute();
        
        else
            status = 0;
    }
    return 0;
}