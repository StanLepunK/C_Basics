#include <stdio.h>

void function(int *arg) {
	*arg = 20;
	printf("*arg: %d\n", *arg);
	printf("arg: %p\n", arg);
}

int main() {
	int value = 0;
	printf("before value: %i\n", value);
	function(&value);

	printf("after value: %i\n", value);
	return (0);
}