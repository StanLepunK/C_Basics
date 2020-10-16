#include <stdlib.h>
#include <stdio.h>

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

void print(t_list *p_list) {
	printf("PRINT\n");
	while(p_list) {
		printf("arg: %i\n",p_list->arg);
		p_list = p_list->next;
	}
}

void change(t_list *c_list) {
	printf("CHANGE\n");
	while(c_list) {
		c_list->arg = 42;
		c_list = c_list->next;
	}
}

int main() {
	t_list *list;
	list = NULL;
	add(&list, 0);
	add(&list, 1);
	add(&list, 2);
	print(list); // work fine 
	change(list);
	print(list); // work fine it's possible te read a second time but why ?
  
	// that's way don't work a second time
	while(list) {
		printf("while arg: %i\n",list->arg);
		list = list->next;
	}

	while(list) {
		printf("while arg: %i\n",list->arg);
		list = list->next;
	}

	return (0);
}