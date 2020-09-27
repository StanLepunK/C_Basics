#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str;
	printf("str: %s\n",str);
	printf("%lu\n",strlen(str));
	bzero(str,1); // ok
	// str = "bonjour"; // bus error
	str = strcpy(str,"bonjour");
	printf("%lu\n",strlen(str));
	printf("%s\n", str);
	bzero(str,strlen(str)); 
	// memset(str, 0, strlen(str)); 
	printf("%lu\n",strlen(str));
	return(0);
}