#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int CheckForPalindrome(char str1[])
{

/*	char str2[10];
	int len=0, i, j;
	while (str1[i] != '\0')
	{
		len = len +1;
		i++;
	}

	for(i = len - 1, j = 0; i >= 0; i--, j++)
	{
		str2[j] = str1[i];
	}

	printf("The string received as %s", str1);
	printf("After reversing the string is: %s", str2);
*/



	int size, i;
	char str2[strlen(str1)];

	printf("String received in the function as %s", str1);
	
	size = strlen(str1);
	for(i = 0; i < strlen(str1) ; i++)
	{
		str2[size] = str1[i];
		size--;	
	}		

	printf("After reversing the string is %s", str2);
	return 1;

}

int main(void) 
{
	char str1[10], str2[10], string3[10];
	int i=0, j=0, count=0, Index=0, loopSize;
	static int finalCount = 0;
	int result;
	int size;

	printf("Enter the source string: ");
	fgets(str1, 20, stdin);

	size = strlen(str1);
//	printf("The string is %s\n", str1);
//	printf("Thestring length is %d\n", size);


	
	while(str1[i] != '\0')
	{

	count = 0;
	Index = 0;
	str2[Index] = str1[i];
	Index++;

		

		for ( j = i+1; j < size - 1; j++)
		{
			
			count++;
			str2[Index] = str1[j];
			Index++;
			loopSize = strlen(str2);
			printf("Before sending the string is %s\n", str2);	
//			printf("And the string length is %d\n", loopSize);		
		
			result = CheckForPalindrome(str2);
			if(result == 1)
				printf("True\n\n");
//			else
//				printf("Flase\n\n");				
		}
	i++;
	}

	return 0;
}
				
