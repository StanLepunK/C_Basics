
// C program to delete a linked list 
#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 
  
void func(float *arg) {
  *arg = 5;
}

int main() { 
  float val = 10;
  printf("%f\n",val);
  func(&val);
  printf("%f\n",val);
  return(0);
} 
