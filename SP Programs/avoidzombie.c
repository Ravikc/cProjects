#include <sys/wait.h> 
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>


int main(void) 
{
    pid_t pid; 
 
    if ((pid = fork()) < 0)
    {
        printf("could not fork"); 
    }
    else if (pid == 0)
    {
        /* first child */  
        if ((pid = fork()) < 0) 
            printf("could not fork error"); 
        else if (pid > 0)   
            exit(0);   
        /* parent from second fork == first child */   
        /*          * We're the second child; our parent becomes init as soon  * as our real parent calls exit() in the statement above.  * Here's where we'd continue executing, knowing that when * we're done, init will reap our status.  */  
            sleep(2);
        printf("second child, parent pid = %d\n", getppid()); 
            exit(0);  
    }  
    if (waitpid(pid, NULL, 0) != pid) 
     /* wait for first child */   
           printf("waiting failed error"); 
 
     
exit(0);
 } 
