#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int glob = 6;     
 
int main(void) 
{
    int  var;
    int var1=5;
   
    pid_t  pid; 
 
    var = 88;
    printf("before fork\n"); 
   
    if ((pid = fork()) < 0)
     {
        printf(" not able to fork child");
    }
     else if (pid == 0) 
     {    
        glob++;  
        var++;
        _exit(0);  
    }  
    else if(pid > 0)
    {
        wait(&var1);
        printf("Inside parent \n"); 
        
    }  
     printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);  
    exit(0);
} 