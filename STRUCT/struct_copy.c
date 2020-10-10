#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This method give the opportunity to attache a method to a struct, that's can be useful sometime.
typedef struct s_obj t_obj;
struct s_obj {
	int x;
	int y;
	void (*copy)(t_obj*, const t_obj*);

};

void function_to_use(t_obj *dst, const t_obj *src) {
	dst->x = src->x;
	dst->y = src->y;
}

int main() {
	t_obj obj_a;
	t_obj obj_b;
	obj_a.x = 10;
	obj_a.y = 100;

	// function linked with the struct
	obj_a.copy = function_to_use;
	obj_a.copy(&obj_b, &obj_a);
	printf("%i\n",obj_b.x);
	printf("%i\n",obj_b.y);

	// direct use of the function
	obj_a.x = 1;
	obj_a.y = 2;
	function_to_use(&obj_b, &obj_a);
	printf("%i\n",obj_b.x);
	printf("%i\n",obj_b.y);

	return (0);
}