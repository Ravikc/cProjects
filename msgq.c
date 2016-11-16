#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>//key_t
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

struct my_msgbuf {
	long mtype;
	char mtext[20];
};

int initializeMessageQueue()
{
	key_t key;
	
	int msgqid;
	if ((msgqid = msgget(key, 0666 | IPC_CREAT)) == -1) {
		perror("msgget");
		exit(1);
	}
	return msgqid;
}

void killMessageQueue(int msgqid)
{
	if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
		perror("msgctl");
		exit(1);
	}
}

void int_send(int num, int msgqid, int type)
{
	printf("Converting num %d to string \n", num);

	struct my_msgbuf buf;

	buf.mtype = type;
	sprintf(buf.mtext,"%d",num); //converting interger to string

	size_t size = sizeof(buf.mtext);

	if (msgsnd(msgqid, &buf, size, 0) == -1) 
		perror("msgsnd");

}

void int_recv(int msgqid, int type)
{
	struct my_msgbuf buf;

	if (msgrcv(msgqid, &buf, sizeof (buf.mtext), type, 0) == -1) { 
		perror("msgrcv");
		exit(1);
	}
         
        printf("Converting \"%s\" to integer \n",buf.mtext);
        int num = atoi(buf.mtext); //converting string to interger
        
	printf("num retrieved from queue: %d\n",num);
}

int main(void)
{
	int msgqid = initializeMessageQueue();
	printf("Created a queue with msqid: %d\n", msgqid);      
	
	int status;
	pid_t pid, wpid;

	
	pid = fork();

	switch (pid) {
		case -1:
			printf("fork failed");
			exit(-1);

		case 0: 

			
			int_recv(msgqid, getpid());

			sleep(2);

			exit(0);

		default:
			

			do
			 {

				printf("Parent: pid=%d ", getpid());
				printf("my child is %d \n", pid);

				int num;
				printf("Enter a number :");
				scanf("%d",&num);

				int_send(num, msgqid, pid);
		
				wpid = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			
			printf("Exiting ... killing message queue \n");
			killMessageQueue(msgqid);
	}
}


