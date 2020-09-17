#include <stdio.h>

void changeStage(int *arg) {
	*arg += 1;
}

int main() {
	int value = 0;
	printf("before value: %i\n", value);
	changeStage(&value);
	printf("after value: %i\n", value);
	return (0);
}