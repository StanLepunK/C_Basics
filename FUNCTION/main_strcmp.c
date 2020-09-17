#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str_a = "machin";
	char *str_b = "machin";
	char *str_c = "michon";
	printf("strcmp(str_a, str_b) %i\n", strcmp(str_a,str_b));
	printf("strcmp(str_a, str_c) %i ", strcmp(str_a,str_c));
}