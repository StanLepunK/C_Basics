#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_obj t_obj;
struct s_obj {
	int value;
	t_obj *next;
};

t_obj *add(t_obj *list, int value) {
	t_obj *temp;
	if(!(temp = (t_obj*)malloc(sizeof(t_obj))))
		return (0);
	temp->value = value;
	temp->next = list;
	return (temp);
}

int main(int num, char **arg) {
	int list [8] = {1, 0, 3, 5, 1, 0, 4, 50};
	int length = sizeof list / sizeof list[0];
	int lost = 0;

	// init list obj
	t_obj *list_obj;
	list_obj = NULL;
	// add value to list_obj
	for(int i = 0 ; i < length ; i++) {
		if(list[i] != lost) {
			list_obj = add(list_obj, list[i]);
		}
	}
	// print list obj
	while(list_obj) {
		printf("value: %i\n",list_obj->value);
		list_obj = list_obj->next;
	}
	return (0);
}