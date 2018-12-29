#include <stdlib.h>

typedef struct node* link;
struct node {
  int item;
  link next;
};

link init() {
  return NULL;
}

link insert(link list, int i) {
  link l = malloc(sizeof(*l));
  l->item = i;
  l->next = list;

  return l;
}

int remove(link list) {
  if(list == NULL) {
    return -1;
  }
  int min = list->item;
  link link = list;
  link prev = list;
  list = list->next;
  while(list != NULL) {
    if(list->item <= min) { // make sure to take the older if equal
      min = list->item;
      link = list;
    }
    prev = list;
    list = list->next;
  }
  prev->next = link->next;
  free(link);

  return min;
}
