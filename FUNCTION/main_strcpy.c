#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *src = "machin";
	char *dst;
  printf("strcpy(dst,src): %s\n", strcpy(dst,src));
  dst = strcpy(dst,src);
	printf("dst: %s\n", dst);
}