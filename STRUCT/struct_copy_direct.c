#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/12642830/can-i-define-a-function-inside-a-c-structure
typedef struct s_obj t_obj;
struct s_obj {
	int x;
	int y;
	t_obj (*copy)(const t_obj*);

};

t_obj copy_x(const t_obj *obj) {
	t_obj new_obj;
	new_obj.x = obj->x;
	return new_obj;
}

t_obj copy_y(const t_obj *obj) {
	t_obj new_obj;
	new_obj.y = obj->y;
	return new_obj;
}

int main() {
	t_obj obj_a;
	obj_a.x = 10;
	obj_a.y = 100;
	obj_a.copy = copy_x;
	t_obj obj_b;
	obj_b = obj_a.copy(&obj_a);
	printf("%i\n",obj_b.x);
	printf("%i\n",obj_b.y);
	obj_a.copy = copy_y;
	obj_b = obj_a.copy(&obj_a);
	printf("%i\n",obj_b.x);
	printf("%i\n",obj_b.y);

	
	return (0);
}