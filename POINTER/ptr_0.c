#include <stdio.h>

void function(int *arg) {
	*arg += 1;
	printf("*arg: %i\n", *arg);
	printf("arg: %i\n", arg);
}

int main() {
	int value = 0;
	printf("before value: %i\n", value);
	function(&value);
	if(value == 1)
		printf("after value: %i\n", value);
	return (0);
}