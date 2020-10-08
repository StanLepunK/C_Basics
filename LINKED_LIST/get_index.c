#include <stdio.h>
#include <stdlib.h>
typedef struct s_list t_list;
struct s_list {
	int arg;
	int id;
	t_list *next;
};

int add(t_list **ref, int index, int arg) {
	t_list *temp;
	temp = NULL;
	if(!(temp = (t_list*)malloc(sizeof(t_list)))) // may be need to malloc to the full size of struct ?
		return (0);
	temp->id = index;
	temp->arg = arg;
	temp->next = (*ref);
	(*ref) = temp;
	return(1);
}

t_list *get(t_list *list, unsigned int index) {
	t_list *current = list;
	int count = 0; 
	while (current) { 
		if (count == index) 
			return(current); 
    count++; 
		current = current->next; 
	}
	return (0);
}

int main() {
	t_list *list;
	list = NULL;

	for(int i = 0; i < 5 ; i++) {
		add(&list,i,i*10);
	}

	t_list *ret;
	ret = NULL;
	ret = get(list, 2);
	if(ret) {
		printf("ret->arg: %i\n",ret->arg);
	}
	
	ret = get(list, 10);
	if(ret) {
		printf("ret->arg: %i\n",ret->arg);
	} else {
		printf("ret == NULL out bound exception\n");
	}
	return (0);
}