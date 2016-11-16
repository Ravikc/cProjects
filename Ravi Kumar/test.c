#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("Enter password: ");
    char password[10];
    int i = 0;
    const char *mypass = "ravi";
    *password = getpass(" ");

    if(!strcmp(password, mypass))
        printf("Correct");
        else
        printf("Not correct");
    
    return 0;
}