#include <stdio.h>
#include <stdlib.h>


void func_pass(int **ref) {
	int *obj = (*ref);
	*obj = 10;
	(*ref) = obj;
}

int *func_ret(int *arg) {
	*arg = 5;
	return (arg);
}


int main() {
	int *ptr;
	if(!(ptr = (int*)malloc(sizeof(int))))
		return (0);
	func_pass(&ptr);
	printf("&ptr: %p\n",&ptr);
	printf("*ptr: %i\n",*ptr);
	printf("ptr[0]: %i\n",ptr[0]);
	printf("func_ret(ptr): %i\n",func_ret(ptr)); // warning: format specifies type 'int' but the argument has type 'int *'
	printf("func_ret(ptr)[0]: %i\n",func_ret(ptr)[0]);
	return (0);
}