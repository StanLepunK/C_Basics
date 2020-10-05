#include <stdlib.h>
#include <stdio.h>

// struct header
typedef struct s_list t_list;
struct s_list {
	int arg;
	t_list *next;
};


int add(t_list **ref, int arg) {
	t_list *temp;
	temp = NULL;
	if(!(temp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	temp->arg = arg;
	temp->next = (*ref);
	(*ref) = temp;
	return(1);
}

void print(t_list *list) {
	printf("list:\n");
	while(list) {
		printf("arg: %i\n",list->arg);
		list = list->next;
	}
}

int main() {
	t_list *list;
	list = NULL;
		// if(!(temp = (t_obj*)malloc(sizeof(t_obj))))
		// return (0);
	add(&list, 0);
	add(&list, 1);
	add(&list, 2);
	print(list);
	print(list);
	return (0);
}