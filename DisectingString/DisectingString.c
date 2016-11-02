#include<stdio.h>
#include<string.h>

int dealWithSpace(int );
int dealWithQuotes(int );
//void dealWithLastWord(void);

char inputString[20];
int flag1=0, quoteFlag1 = 0;
 
int main(void){
 int length;
int i=0, j=0;

printf("Enter string: ");
fgets(inputString, 20, stdin);



// printf("the inputString is: %s", inputString);

length = (int)strlen(inputString);
// printf("%d", length);

while(i < length-2) {
	if( (inputString[i] == (char)32 || inputString[i] == (char)'\0') && ( inputString[i+1] != (char)34) )
		i = dealWithSpace(i);
	else if(inputString[i] == (char)34)
		i = dealWithQuotes(i);
	i++;
	}
//	dealWithLastWord(); 
	return 0;
}	

int dealWithSpace(int index) 
{
	char tempArray[10];
	int  k = 0, i = 0;
	
	flag1 = index + 1;
	index++;
	while(inputString[index] != (char)32 || inputString[index] != '\0')
		index++;
	for(i = flag1, k = 0; i <= index; i++, k++)
		tempArray[k] = inputString[i];
	
	printf("Token: %s", tempArray);
	index += 1;
	return index;
}

int dealWithQuotes(int index)
{
	char tempArray[10];
	int i = 0, k = 0;
	
	quoteFlag1 = index + 1;
	while(inputString[index] != (char)34 || inputString[index] != '\0')
		index++;
	for(i = flag1, k = 0; i <= index; i++, k++)
		tempArray[k] = inputString[i];
	printf("Token: %s", tempArray);
	index += 2;
	return index;

}

// void dealWithLastWord(){
// 	int i;
// 	printf("Token: ");
// 	for(i = flag1; i < strlen(inputString); i++)
// 		printf("%c", inputString[i]);
// 	printf("\n");
// }

