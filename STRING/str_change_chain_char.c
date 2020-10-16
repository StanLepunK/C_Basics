#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list t_list;
struct s_list {
  int arg;
  t_list *next;
};

int add_to_t_list(t_list **ref, int arg) {
	t_list *temp;
	temp = NULL;
	if(!(temp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	temp->arg = arg;
	temp->next = (*ref);
	(*ref) = temp;
	return(1);
}

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

void print_t_list(t_list *p_list, char *name) {
	printf("PRINT t_list: %s\n", name);
	while(p_list) {
		printf("arg: %i\n",p_list->arg);
		p_list = p_list->next;
	}
}

void add_to_key_list(int *key, t_list **ref) {
  if(*key) {
    add_to_t_list(&(*ref),*key);
    *key = 0;
  }
}

void build_key_from_str(t_list **ref, char target, char *str) {
  int in = 0;
  int out = 0;
  while(*str) {
    if(*str == target) {
      add_to_key_list(&out, ref);
      in++;
    } else { 
      add_to_key_list(&in, ref);
      out--;  
    }
    str++;
  }
  add_to_key_list(&out, ref);
  add_to_key_list(&in, ref);
  reverse(ref);
}


int main() {
  int length = 10;
  char c_lock = '.';
  char c_key = '#';
	char *str_lock;
  char *str_key;
  
  str_lock = (char*)malloc(sizeof(char) * length);
  str_lock = strcpy(str_lock, "..A..AA.");
  str_key = (char*)malloc(sizeof(char) * length);
  str_key = strcpy(str_key, "..#.#.."); // this one is not possible
  //src = strcpy(src, "..##.."); // this one is good, because the chain to change as same of chain target

  
  
  t_list *lock;
  lock = NULL;
  build_key_from_str(&lock, c_lock, str_lock);
  printf("str_lock %s\n", str_lock);
  print_t_list(lock, "lock");

  t_list *key;
  key = NULL;
  build_key_from_str(&key, c_key, str_key);
  printf("\nstr_lkey %s\n", str_key);
  print_t_list(key, "key");


	return(0);
}