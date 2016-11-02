#include<stdio.h>
#include<string.h>

void main() {
	char str1[10] = "Ravi";
	int i, j, counter;
        counter = strlen(str1) -1;
        char str2[10];

        for(i = 0; i < strlen(str1) ; i++)
        {
                str2[counter] = str1[i];
                counter--;
        }

	printf("%s", str2);
}
