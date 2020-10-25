#include <math.h>
#include <stdio.h>



int sqrt_ceil(float value) {
  int arg = 0;
  int max = 46341; // max for the int value
  if(value < 0) {
    return(0);
  }


  while(arg * arg < value && arg * arg < max) {
    arg++;
  }
  return (arg);
}

int main() {
  int arg = 10;
  printf("sqrt(arg) %f\n",sqrt(arg));
  printf("sqrt_ceil(arg) %i\n",sqrt_ceil(arg));
  return (0);
}