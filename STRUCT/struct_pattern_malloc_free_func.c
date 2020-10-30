#include <stdlib.h>
#include <stdio.h>

// https://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c
typedef struct s_vec2 t_vec2;
struct s_vec2 {
	float *data;
  size_t size;

  void (*set_x)(t_vec2*, float);
  void (*set_y)(t_vec2*, float);
  float (*get_x)(t_vec2*);
  float (*get_y)(t_vec2*);
};

t_vec2 *new_vec2() {
  t_vec2 *buf;

  buf = NULL;
  if(!(buf = (t_vec2*)malloc(sizeof(t_vec2))))
    return (0);
  buf->size = 2;
  if(!(buf->data = (float*)malloc(sizeof(float) * buf->size))) {
    free(buf);
    return (0);
  }
  return buf;
}

void func_set_x(t_vec2 *v, float x) {
  v->data[0] = x;
}

void func_set_y(t_vec2 *v, float y) {
  v->data[1] = y;
}

float func_get_x(t_vec2 *v) {
  return v->data[0];
}

float func_get_y(t_vec2 *v) {
  return v->data[1];
}

void init_vec2(t_vec2 *vec) {
  vec->set_x = func_set_x;
  vec->set_y = func_set_y;
  vec->get_x = func_get_x;
  vec->get_y = func_get_y;
}

void free_vec2(t_vec2 *vec) {
  free(vec->data);
  free(vec);
}

int main() {
  t_vec2 *a = new_vec2();
  init_vec2(a);
  float val = 5;
  a->set_x(a,val);
  a->set_y(a,6);
  printf("vec %f %f\n",a->get_x(a), a->get_y(a));
  printf("vec %f %f\n",a->get_x(a), a->get_y(a));
  free_vec2(a);
  printf("vec %f %f\n",a->get_x(a), a->get_y(a));

  return(0);
}