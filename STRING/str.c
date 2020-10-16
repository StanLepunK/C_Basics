#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_obj t_obj;
struct s_obj {
	char *str;
};

int main() {
	char *str;
	t_obj obj;
	if (!(obj.str = (char*)malloc(sizeof(char))))
		return (0);
	obj.str = strcpy(obj.str, "truc");
	printf("%s\n",obj.str);
	free(obj.str);
	return(0);
}