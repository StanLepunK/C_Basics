#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char a = '.';
  char b = '#';
	char *dst = "..A";
  char *src = "##..";

  dst = (char*)malloc(sizeof(char) * 10);
  dst = strcpy(dst, "..A");
  src = (char*)malloc(sizeof(char) * 10);
  src = strcpy(src, "..#.#..");

  printf("before dst %s\n", dst);
  int index_dst = 0;
  int index_src = 0;
  while(index_dst < strlen(dst)) {
    if(dst[index_dst] == a) {
      while(index_src < strlen(src)) {
        if(src[index_src] == b) {
          dst[index_dst] = src[index_src];
          break;
        }
        index_src++;
      }
    }
    index_dst++;
  }
  printf("after dst %s\n", dst);
	return(0);
}