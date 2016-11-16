#include<stdio.h>
#include<stdlib.h>

#define BUFFSIZE 4096 

 
int main(void) {
int n;
char   buf[BUFFSIZE]; 
 
while ((n = read(1, buf, BUFFSIZE)) > 0)
         if (write(1 , buf, n) != n)
    printf(" could not write"); 
 
    if (n < 0)
        printf("could not read "); 
 
    exit(0);
} 
