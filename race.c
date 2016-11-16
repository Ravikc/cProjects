#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

static void charatatime(char *);

int main(void)
{
	pid_t pid;
	if ((pid=fork())<0){
		perror("fork error\n");}
	else if(pid==0){
		charatatime("Output from child Advanced programming in the unix environment\n");
	}
	else{
	charatatime("Output from parent 1234567891011121314151617181920\n");
	}
	exit(0);
}

static void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;(c=*ptr++)!=0;)
			putc(c,stdout);

}
