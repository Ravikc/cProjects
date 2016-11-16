#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int glob = 6;     
 
int main(void) 
{
    int  var, status;
   
    pid_t  pid; 
 
    var = 88;
    printf("before fork\n"); 
   
    if ((pid = fork()) < 0)
     {
         
        printf("fork error");
    }
     else if (pid == 0) 
     {    
        glob++;  
        var++;
          printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
        _exit(0);  
    }  
    else if(pid > 0)
    {
        wait(&status);
        printf("Inside parent\n");
    }
           
     
    exit(0);
} 