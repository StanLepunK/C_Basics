#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_child t_child;
struct s_child {
	char *str;
};

typedef struct s_mother t_mother;
struct s_mother {
	int arg;
	t_child *child;
};

int func_init(t_mother *mother, t_child *child) {
	mother->child = child; // need to link to avoid seg fault
	if (!(mother->child->str = (char*)malloc(sizeof(char))))
		return (0);
	return (1);
}

void func(t_mother *mother) {
	mother->child->str = strdup("truc");
	printf("%s\n",mother->child->str);
}

int main(int num, char **arg) {
	t_mother mother;
	// need to declare child to the same level of mother 
	// to can use child like mother without lost the data when we change the scope
	t_child child; // need to declare to avoid seg fault
	func_init(&mother, &child);
	func(&mother);
	printf("%s\n",mother.child->str);
	free(mother.child->str);
	return (0);
}