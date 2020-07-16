#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NOT_PRESENT -1

typedef int * List_ptr;

int binary_search(List_ptr list,int value,int start,int end) {
  int mid = floor((start + end)/2);
  if (list[mid] == value) return mid;
  if (start == end) return NOT_PRESENT;
  if (value > list[mid]) return binary_search(list, value, mid + 1, end);
  return binary_search(list, value, start, mid - 1);
};

int main(void) {
  List_ptr list = malloc(sizeof(int) * 4);
  list[0] = 10;
  list[1] = 20;
  list[2] = 30;
  list[3] = 40;
  int value = 40;
  int index = binary_search(list,value,0,3);
  printf("Index : %d\n",index);
  return 0;
};