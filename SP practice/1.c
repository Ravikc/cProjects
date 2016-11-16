#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void RecordAndExecute(void)
{
    printf("Recording has started, file is log.txt\n");
    char command[10], output[50], commandFile[10];
    FILE *fp = fopen("log.txt", "w");
    while(true)
    {
        printf("_Joker__");
        fgets(command, sizeof(command), stdin);
        command[strlen(command)-1] = '\0';
        if(!strcmp(command, "stop"))
        {
            printf("Recording has stopped\n");
            fclose(fp);
            return;            
        }
      
        sprintf(commandFile, "echo %s >> log.txt", command);
        sprintf(output, "%s >> log.txt", command);
        system(commandFile);
        system(output);
        fprintf(fp, "\n");
        system(command);
    }
}

int main(void)
{
    char command[10];
    int i = 0;
    while(true)
    {
        printf("_Jok3r__");
        fgets(command, sizeof(command), stdin);
        command[strlen(command)-1] = '\0';
        if(!strcmp(command, "exit"))
            return 0;
        else if(!strcmp(command, "record"))
            RecordAndExecute();
        else    
            system(command);
    }
    return 0;
}