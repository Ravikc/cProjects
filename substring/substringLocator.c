#include<stdio.h>
#include<string.h>
int count = 0;

int main(void) {
char str1[10], str2[10], temp[10];
int i=0, j=0, index=0;

printf("Enter string 1: ");
scanf("%s", str1);
printf("\nEnter string 2: ");
scanf("%s", str2);

while(str1[i] != '\0') {
	while(str2[j] != '\0') {
		if(str1[i] == str2[j]) {
			temp[index] = str1[i];
			index++;
			i++;
			j++;
			count++;
			}
		else if(str1[i] != str2[j] && count >1)
			goto end;
		else{
			j++;
			count = 0;
			index = 0;	
		}
		
		}
	i++;
	j=0;
	}
end: if(count > 1){
	printf("Substring exists ");
	printf(" %s\n", temp);
	}
	else
	printf("Does not exist\n");
return 0;
}
