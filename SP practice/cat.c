#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int i,fd[10],sucr;
	char cstr[100],buf[256];
	for(i=1;i<=argc;i++){
		fd[i]=open(argv[i],O_RDONLY,0777);
	
	}
	if(argc==1){
		gets(cstr);
		puts(cstr);
	}
	for(i=1;i<=argc;i++){
		while((sucr=read(fd[i],buf,256))>0)
			write(1,buf,sucr);
		}
		close(fd);
	return 0;
}
