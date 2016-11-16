#include<stdio.h>
#include<string.h>

void parse(char *line)
{
    int i = 0, counter = 1;
    printf("Token[%d]: ", counter++);
    while(line[i] != '\0')
    {
       
        if(line[i] != (char)32 && line[i] !=(char)34)
            printf("%c", line[i]);
        else if(line[i] == (char)32)
        {
            printf("\nToken[%d]: ", counter++);
        }
        else if(line[i] == (char)34)
        {
            i++;
            while(line[i] != (char)34)
            {
                printf("%c", line[i]);
                i++;
            }
        }
        i++;
    }
    
}


int main(void)
{
    char line[30];
    printf("Enter statement: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';
    parse(line);
    return 0;
}