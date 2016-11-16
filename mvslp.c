#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
void main()
{
	struct timeval tv;
	char str[20],fl1[20],fl2[20],*f1,*f2;
	while(1)
	{
		printf("cmdprompt>>");
		scanf("%s",str);
		if(strcmp(str,"rename")==0)
		{
			printf("Source file");
			scanf("%s",fl1);
			printf("Destination file");
			scanf("%s",fl2);
			f1=&fl1;
			f2=&fl2;
			link(f1,f2);
			unlink(f1);
			
		}
		else if(strcmp(str,"sleep1")==0)
		{
			//printf("The system is entering sleep mode for 4.5 seconds.....");
			printf("System entered sleep mode for 4.5 seconds\n");
			tv.tv_sec=4;
			tv.tv_usec=500000;
			select(0,NULL,NULL,NULL,&tv);
			printf("Exiting sleep mode..");
		}
		else if(strcmp(str,"exit")==0)
			exit(0);
		else
			system(str);
	}return;
}
