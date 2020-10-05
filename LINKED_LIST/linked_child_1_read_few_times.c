#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_child t_child;
struct s_child {
	int id;
	t_child *next;
};

typedef struct s_mother t_mother;
struct s_mother {
	t_child *child;
	t_mother *next;
};

int add_child(t_child **ref, int rank) {
	t_child *temp;
	temp = NULL;
	if(!(temp = (t_child*)malloc(sizeof(t_child))))
		return (0);
	temp->id = rank;
	temp->next = (*ref);
	(*ref) = temp;
	return(1);
}

int dup(t_child **ref, t_child *src) {
	int rank = 0;
	int ret = 0;

  while(src) {
		ret = add_child(ref, rank);
		if(!ret)
			break;
		rank++;
		src = src->next;
	}
	return(ret);
}

int add_mother(t_mother **ref, t_child *c) {
	t_mother *temp;
	int ret = 0;
	temp = NULL;
	if(!(temp = (t_mother*)malloc(sizeof(t_mother))))
		return (0);
	temp->child = NULL;
	ret = dup(&temp->child, c);
	temp->next = (*ref);
  (*ref) = temp;
	return(ret);
}

void print_child(t_child *c) {
	printf("print child:\n");
	while(c) {
		printf("id: %i\n",c->id);
		c = c->next;
	}
}

void print_mother(t_mother *m) {
	printf("print mother:\n");
	// with that we can read an infinite time.
	print_child(m->child);
	// with this line we can read only one time the loop
	// while(m->child) {
	// 	printf("id: %i\n",m->child->id);
	// 	m->child = m->child->next;
	// }
}




int main() {
	t_child *c;
	c = NULL;
	for(int i = 0 ; i < 4 ; i++) {
		add_child(&c, i);
	}

	t_mother *m;
	m = NULL;
	add_mother(&m, c);
	print_child(c);
	print_child(c);
	print_mother(m);
	print_mother(m);
	return(0);
}