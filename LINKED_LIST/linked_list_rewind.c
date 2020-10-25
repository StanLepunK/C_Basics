#include <stdlib.h>
#include <stdio.h>

typedef struct s_list t_list;
struct s_list {
	int arg;
	t_list *next;
	// t_list *previous;
};


void reverse(t_list **ref) {
	t_list *prev = NULL;
	t_list *current = *ref;
	t_list *next = NULL;

	while(current) {
		next = current->next;
		current->next = prev; // reverse currnt ptr
		prev = current; // move ptr to ahead
		current = next;
	}
	(*ref) = prev;
}

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

t_list *header_ptr(t_list *ptr) {
	t_list *header = ptr;
	return (header);
}

void navigate(t_list *p_list) {
	t_list *header = header_ptr(p_list);
	printf("header adress: %p\n",header);
	printf("header arg: %i\n",header->arg);

	printf("navite once\n");
	while(header) {
		printf("arg: %i\n",header->arg);
		header = header->next;
	}
	header = header_ptr(p_list);
	// printf("header arg: %i\n",header->arg);
	// reverse(&p_list);
	printf("navite twice\n");
	while(header) {
		printf("arg: %i\n",header->arg);
		header = header->next;
	}
}


int main() {
	t_list *list;
	list = NULL;
	add(&list, 0);
	add(&list, 1);
	add(&list, 2);
  add(&list, 3);
	navigate(list); // work fine 


	return (0);
}