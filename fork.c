#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void parse(char *line,char **argv){
	while(*line!='\0'){
		while(*line==' ' || *line=='\n' || *line=='\t')
			*line++='\0';
		*argv++=line;
	while(*line!=' ' && *line!='\t' && *line!='\0' && *line!='\n')
	line++;
	}
	*argv='\0';
}

void execute(char **argv){
	pid_t pid,wpid;
	int status;
	printf("Forking a child\n");
	pid=fork();
	printf("Command line process id is %d\n",pid);
	if(pid<0){
		perror("fork failed\n");
		exit(1);
	}
	else if(pid==0){
		printf("Executing the command %s in child\n",argv[0]);
		if(execvp(argv[0],argv)==-1){
			perror("execvp failed\n");
			exit(1);
		}
	}
	else{
		do{
			printf("In parent waiting for child to execute\n");
			wpid=waitpid(pid,&status,WUNTRACED);
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return;
}

main(void)
{
	char line[1024];
	char *argv[64];
	while(1){
	printf("Shell->\n");
	gets(line);
	parse(line,argv);
	if(strcmp(line,"exit")==-1)
		exit(1);	
	execute(argv);
}
} 
