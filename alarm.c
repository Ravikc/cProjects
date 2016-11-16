#include<errno.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>

void wakeup(int sig_no){
	printf("Hello\n");
	printf("----------\n");
}

int main(){
	int i;
	struct sigaction action;
	action.sa_handler =(void(*)(int))wakeup;
	action.sa_flags=SA_RESTART;
	sigemptyset(&action.sa_mask);
	if(sigaction(SIGALRM,&action,0)==-1){
		perror("sigaction");}
	while(1){
		alarm(5);
		pause();
		printf("Waiting for alarm\n");
	}
	return 0;
}
