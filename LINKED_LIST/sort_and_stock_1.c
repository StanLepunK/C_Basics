#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_obj t_obj;
struct s_obj {
	int value;
	t_obj *next;
};

int add(t_obj **ref, int value) {
	t_obj *temp;
	if(!(temp = (t_obj*)malloc(sizeof(t_obj))))
		return (0);
	temp->value = value;
	temp->next = (*ref);
	(*ref) = temp;
	return (1);
}

static void reverse(t_obj **ref) {
	t_obj *prev = NULL;
	t_obj *current = *ref;
	t_obj *next = NULL;

	while(current) {
		next = current->next;
		current->next = prev; // reverse currnt ptr
		prev = current; // move ptr to ahead
		current = next;
	}
	(*ref) = prev;
}

void print_list_obj(t_obj *list_obj) {
	while(list_obj) {
		printf("value: %i\n",list_obj->value);
		list_obj = list_obj->next;
	}
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
			add(&list_obj, list[i]);
		}
	}
	printf("list\n");
	print_list_obj(list_obj);
	printf("reverse list\n");
	reverse(&list_obj);
	print_list_obj(list_obj);
	return (0);
}