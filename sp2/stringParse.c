#include<stdio.h>
#include<string.h>

char inputString[20], tempArray[10];
char outputString[10][10];

int main() 
{
    int i = 0, j = 0, outputIndex = 0, k = 0;
    printf("String: ");
    fgets(inputString, sizeof(inputString), stdin);
   // inputString[strlen(inputString)-1] = '\0';

    while(i < strlen(inputString) + 1)
    {
        if((inputString[i] == (char)32 || inputString[i] == '\0') && (inputString[i-1] != '\0'))
        {
            strcpy(outputString[outputIndex++], tempArray);
            memset(tempArray, 0, sizeof(tempArray));
            j= 0;                
        }
        else if(inputString[i] == (char)34)
        {
            memset(tempArray, 0, sizeof(tempArray));
            i++;
            while(inputString[i] != (char)34)
            {
                tempArray[j++] = inputString[i];
                i++;
            }
            i++;
            strcpy(outputString[outputIndex++], tempArray);
            memset(tempArray, 0, sizeof(tempArray));
            j= 0;                
        }
        else
        {
            tempArray[j++] = inputString[i];
        }
        i++;
    }
    for(k = 0; k < outputIndex; k++)
        printf("Tokens %d: %s\n", k+1, outputString[k]);
    return 0;
}