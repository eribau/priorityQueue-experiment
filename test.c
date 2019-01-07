#include <stdlib.h>
#include <stdio.h>

#include "linkedListInt.h"

void printList(link list) {
  link l = list->next;
  while(l != NULL) {
    printf("|%d|->", l->item);
    l = l->next;
  }
  printf("\n");
}

void main() {
  link list = init();

  list = insert(list, 45);
  list = insert(list, 41);
  list = insert(list, 42);

  printList(list);
  int min = removeMin(list);
  printf("Min: %d\n", min);
  printList(list);
  min = removeMin(list);
  printf("Min: %d\n", min);
  printList(list);
  min = removeMin(list);
  printf("Min: %d\n", min);
  printList(list);

  list = insert(list, 13);
  printList(list);
  min = removeMin(list);
  printf("Min: %d\n", min);
  printList(list);
}
