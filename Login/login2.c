#include<stdio.h>
#include<string.h>
#include<sys/ioctl.h>

struct record {
char userName[20];
char password[20];
};


void main() {
system("clear");
struct winsize w; 
    ioctl(0, TIOCGWINSZ, &w); 
    int columns = w.ws_col;

int i;
columns = columns/3 + 5;
char spaces[columns]; 
for(i = 0;i < columns; i++)
	spaces[i] = ' ';

int choice;
restart: 
printf("%s", spaces);
printf("1. Sign Up \t 2. Sign In\n");
 printf("%s", spaces);
scanf("%d", &choice);

int c;
while ((c = getchar()) != EOF && c != '\n');

if(choice == 1){
	
	char tempUserName[20];
	char tempPassword[20];
	
beginning:
	printf("%s", spaces);
	printf("Choose a user name: ");
	fflush(stdout);
	fgets(tempUserName, sizeof(tempUserName), stdin);
	fflush(stdout);
	// checking for white spaces in username

	for (i = 0; i < sizeof(tempUserName); i++) {
	if(tempUserName[i] == ' ') {
//	printf("%s" ,spaces);
	printf("Spaces are not allowed in user name, please try again\n\n\n");
	goto beginning; 
		}	
	}
	printf("%s", spaces);
	printf("Choose a password: ");
	fgets(tempPassword, sizeof(tempPassword), stdin);

	struct record user;
	strcpy(user.userName, tempUserName);
	strcpy(user.password, tempPassword);

	FILE *fp = fopen("vault.txt", "ab");
	fwrite(&user, sizeof(user), 1, fp);
	fclose(fp);
	printf("%s", spaces);
	printf("Account created, try signing in using the same username and password \n");
	goto restart;
	}

// SIGN IN OPTIONS

else if(choice == 2) {
struct record search;
char tempUserName[20], tempPassword[20];
FILE *fp = fopen("vault.txt", "rb");
	if(fp == NULL){
		printf("%s", spaces);
		printf("Try signing up first\n");
		goto restart;
	}
	printf("%s", spaces);	
	printf("Username :");
	fgets(tempUserName, sizeof(tempUserName), stdin);
	 printf("%s", spaces);
	printf("Password: ");
	fgets(tempPassword, sizeof(tempPassword), stdin);

	while(fread(&search, sizeof(struct record), 1, fp) != 0){ 
	if( strcmp(tempUserName, search.userName) == 0 && strcmp(tempPassword, search.password) == 0 ){			           				    			 printf("%s", spaces);
					printf("Acccess Granted!\n");
					return;
				}

		       	
	}
	 printf("%s", spaces);
	printf("Username/password does not match\n");
	
}
else {
	 printf("%s", spaces);
	printf("Invalid Entry, try again\n");
	main();
	}
}
