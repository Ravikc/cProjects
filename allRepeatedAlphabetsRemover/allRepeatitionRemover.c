#include<stdio.h>
int main(void) {
char source[20], result[20], tempChar;
int i, j, flag = 0;
static int index = 0;
printf("Enter string\n");
scanf("%s", source);

for(i = 0; i < 20; i++) {
	tempChar = source[i];
	for(j = 0; j < 20; j++) {
		if(source[j] == tempChar && i != j)
			flag = 1;
			}
	if(flag == 0) {
		result[index] = tempChar;
		index++;
		}
	flag = 0;
	}
printf("New string : %s\n", result);
return 0;
}
