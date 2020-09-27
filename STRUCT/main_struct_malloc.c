#include <stdlib.h>

typedef struct s_child t_child;
struct s_child {
	char *str;
};

typedef struct s_mother t_mother;
struct s_mother {
	t_child *child;
};

int main(int num, char **arg) {
	t_mother mother;
	// tricky phase to avoid the seg fault
	t_child child;
	mother.child = &child;
  // the malloc bellow cause a seg fault when int main() can pass aguments.
	if (!(mother.child->str = (char*)malloc(sizeof(char))))
		return (0);
	return (0);
}