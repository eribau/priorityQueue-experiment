#include <stdlib.h>
#include <stdio.h>

#include "list_double.h"
#include "heap_double.h"

void printList(link list) {
  link l = list->next;
  while(l != NULL) {
    printf("|%f|->", l->item);
    l = l->next;
  }
  printf("\n");
}

void testLinkedList() {
  printf("List test: \n");
  link list = init();

  list = insert(list, 45.0);
  list = insert(list, 41.0);
  list = insert(list, 42.0);

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

  list = insert(list, 13.0);
  printList(list);
  min = removeMin(list);
  printf("Min: %d\n", min);
  printList(list);
}

void testHeap() {
  printf("Heap test:\n");
  heapInit(1);
  heapInsert(45);
  heapInsert(41);
  heapInsert(42);
  printHeap();

  double min = heapDelmin();
  printf("Min: %f\n", min);
  printHeap();
  min = heapDelmin();
  printf("Min: %f\n", min);
  printHeap();
  min = heapDelmin();
  printf("Min: %f\n", min);
  printHeap();
  printf("Check heap order:\n");
  heapInsert(17);
  heapInsert(16);
  heapInsert(15);
  heapInsert(14);
  heapInsert(13);
  printHeap();
  min = heapDelmin();
  printf("Min: %f\n", min);
  printHeap();
}

void main() {
  testLinkedList();
  testHeap();
}
