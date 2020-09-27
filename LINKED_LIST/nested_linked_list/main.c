#include <stdlib.h>
#include <stdio.h>
// brick
typedef struct s_brick t_brick;
struct s_brick {
	char *str;
	t_brick *next;
};

typedef struct s_wall t_wall;
struct s_wall {
	t_brick *brick;
	t_wall *next;
};


t_brick *add_brick(t_brick *brick, char *str);
t_wall *add_wall(t_wall *wall, t_brick *brick);
void print_brick(t_brick *brick);
void print_wall(t_wall *wall);




// main
int main() {
	t_wall *wall;
	t_brick *brick;
	brick = NULL;
	wall = NULL;

	brick = add_brick(brick, "brique rouge");
	brick = add_brick(brick, "brique jaune");
	brick = add_brick(brick, "brique orange");

	wall = add_wall(wall, brick);

	print_wall(wall);
	return (0);
}

t_wall *add_wall(t_wall *wall, t_brick *brick) {
	t_wall *temp_wall;
	temp_wall = (t_wall*)malloc(sizeof(t_wall));
	if(temp_wall) {
		temp_wall->brick = brick;
		temp_wall->next = wall;
	}
	return (temp_wall);
}


t_brick *add_brick(t_brick *brick, char *str) {
	t_brick *temp_brick;
	temp_brick = (t_brick*)malloc(sizeof(t_brick));
	if(temp_brick) {
		temp_brick->str = str;
		temp_brick->next = brick;
	}
	return (temp_brick);
}

void print_brick(t_brick *brick) {
	while(brick) {
		printf("%s\n",brick->str);
		brick = brick->next;
	}
}


void print_wall(t_wall *wall) {
	while(wall) {
		print_brick(wall->brick);
		wall = wall->next;
	}
}