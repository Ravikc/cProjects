#include<stdio.h>
#include<string.h>

struct record {
	char userName[20];
	char password[20];
};

void signIn();
struct record signUp();



void main() {
int choice, counter = 0;
struct record temp;
struct record array[10];
printf("\t\t 1. Sign In \n\t\t 2. Sign Up\n");
scanf("%d", &choice);

int c;
while ((c = getchar()) != EOF && c != '\n');

if(choice == 1){
	signIn();
	}

else if(choice == 2){
	temp = signUp();
	array[counter] = temp;
	counter++;

	
        FILE *fp = fopen("vault", "ab");
        fwrite(&temp, sizeof(user), 1, fp);
        fclose(fp);
	}

else {
	printf("Invalid Entry, try again\n");
	main();
	}	
}

void signIn(){
	printf("Sign In\n");
}

struct record signUp(){

char tempUserName[20];	
char tempPassword[20];
int i;
	printf("Sign Up\n");
//	FILE *fp = fopen("vault", "ab");
	printf("Choose a user name\n");
	fgets(tempUserName, sizeof(tempUserName), stdin);

	// checking for white spaces in username

	for (i = 0; i < sizeof(tempUserName); i++) {
		if(tempUserName[i] == ' ') {
			printf("Spaces are not allowed in user name, please try again\n\n\n");
			signUp();
			break;
			}
		}
	
	printf("Enter a password\n");
	fgets(tempPassword, sizeof(tempPassword), stdin);	
			
	struct record user;
	strcpy(user.userName, tempUserName);
	strcpy(user.password, tempPassword);

	FILE *fp = fopen("vault", "ab");
	fwrite(&user, sizeof(user), 1, fp);
	fclose(fp);
	return user;
}

void signIn() {
FILE *fp = fopen("vault", "rb");
char tempUserName[20], tempPassword[20];

	printf("Enter user name\n");
	scanf("%s", tempUserName);
	printf("Enter password\n");
	scanf("%s", tempPassword);

	while(fread(&user,sizeof(user),1,fp))
                    {
                        if(strcmp(tempUserName,user.userName)==0)
                        {
                            printf("\n\t\t %s\t %s",user.userName,user.password);
                            getch();
                            break;
                        }
                    }
	fclose(fp);
}
