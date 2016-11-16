#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int parse();

int main()
{
	char str[20], prompt[ ]="vysh>>";
	while(1){
		printf("%s",prompt);
		parse();
		return 0;
	}
}

int parse() {
	char s[80],ch;
	int i=0,d,j,token=0;
	printf("Enter the command line arguments\n");
	gets(s);
	printf("\nToken:%d\t",++token);
	while(s[i]!='\0'){
		d=s[i];
		if((d!=32) && (d!=34)){
			printf("%c",d);
		}
		else if(d==32){
		if((s[i]==' ') && (s[i+1]!='"')){
			printf("\nToken:%d\t",++token);
	}	
	}	
	else
		if((d==34) && (d!=32)){
			printf("\nToken:%d\t",++token);
			i++;	
		        while(s[i]!='"'){
			printf("%c",s[i]);
			i++;
		}
}
	i++;
	}
	return 0;
}

