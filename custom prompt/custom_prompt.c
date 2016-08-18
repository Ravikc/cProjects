#include<stdio.h>
void main() {
char command[10];
FILE *fp;
fp = fopen("log.txt","w");

while(1){
	printf(">>ravi>>");
	scanf("%s", command);
	if(strcmp(command,"exit")) {
		system(command);
		fprintf(fp, "%s", command);
		fprintf(fp, "\n");
			}
	else{
		fclose(fp);
		return;
		}
	}

}
