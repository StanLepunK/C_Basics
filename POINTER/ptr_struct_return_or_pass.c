#include <stdio.h>
#include <stdlib.h>

typedef struct s_obj t_obj;
struct s_obj {
	int arg;
};

void func_pass(t_obj **ref) {
	t_obj *obj = (*ref);
	obj->arg = 10;
	(*ref) = obj;
}

t_obj *func_ret(t_obj *obj) {
	obj->arg = 5;
	return (obj);
}

int main() {
	t_obj *ptr;
	ptr = NULL;
	if(!(ptr = (t_obj*)malloc(sizeof(t_obj))))
		return (0);
	func_pass(&ptr);
	printf("func_pass(&ptr): %i\n", ptr->arg);
	printf("func_ret(ptr)->arg: %i\n", func_ret(ptr)->arg);
	free(ptr);
	return (0);
}
