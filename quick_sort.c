#include <stdlib.h>
#include <stdio.h>

typedef int * List_ptr;

void swap(List_ptr list,int pos1,int pos2) {
  int temp = list[pos1];
  list[pos1] = list[pos2];
  list[pos2] = temp;
};

int partition(List_ptr list,int start,int end) {
  int pivot = list[end];
  int position = start - 1;
  int index = start;
  while (index <= end) {
    if (list[index] < pivot) {
      position++;
      swap(list, position, index);
    }
    index++;
  }
  position++;
  swap(list, position, end);
  return position;
};

void quick_sort(List_ptr list,int start,int end) {
  if(start < end) {
    int index = partition(list, start, end);
    if (start < index - 1) quick_sort(list, start, index - 1);
    if (start < index + 1) quick_sort(list, index + 1, end);
  }
};

int main(void) {
  List_ptr list = malloc(sizeof(int) * 4);
  list[0] = 13;
  list[1] = 8;
  list[2] = 5;
  list[3] = 10;
  quick_sort(list,0,3);
  for(int i=0; i < 4; i++) {
    printf("%d\n",list[i]);
  }
  return 0;
};