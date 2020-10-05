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

int main() {
	t_child *c;
	c = NULL;
	for(int i = 0 ; i < 4 ; i++) {
		add_child(&c, i);
	}

	t_mother *m;
	m = NULL;
	add_mother(&m, c);
	while(m->child) {
		printf("id: %i\n",m->child->id);
		m->child = m->child->next;
		printf("m->child %p\n", m->child);
		if(m->child == NULL) 
			printf("m->child NULL\n");
	}
	return(0);
}