#include <stdlib.h>
#include <stdio.h>

// struct header
typedef struct s_list t_list;
struct s_list {
	char *str;
	t_list *next;
};

// method header
t_list *add_link(t_list *list, char *str);
void print_list(t_list *list);

// main
int main() {
	t_list *list;
	list = NULL;

	list = add_link(list, "truc");
	list = add_link(list, "machin");
	list = add_link(list, "bidule");

	print_list(list);
	return (0);
}


t_list *add_link(t_list *list, char *str) {
	t_list *temp_list;
	temp_list = (t_list*)malloc(sizeof(t_list));
	if(temp_list) {
		temp_list->str = str;
		temp_list->next = list;
	}
	return (temp_list);
}

void print_list(t_list *list) {
	while(list) {
		printf("%s\n",list->str);
		list = list->next;
	}
}