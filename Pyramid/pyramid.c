#include<stdio.h>
#include<sys/ioctl.h>

void main() {

system("clear");
int i, j, lines;
char spaces[100];

    struct winsize w; 
    ioctl(0, TIOCGWINSZ, &w); 

    int columns = w.ws_col; 
  

printf("How many rows? ");
scanf("%d", &lines);

for(i = 0; i < (columns/2) - lines ; i++)	// To align the last row
	spaces[i] =(char) 32;			// ASCII for blank space


for(i=1;i<=lines;i++){
	printf("%s", spaces);
	for(j=0;j < lines - i  ;j++)
		printf(" ");

	for(j=1; j <= i; j++)
		printf("%d ", j);
		printf("\n");
	}		
}	
