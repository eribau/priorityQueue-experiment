#include <stdlib.h>

typedef struct node* link;
struct node {
  double item;
  link next;
};

link init() {
  link lnk = malloc(sizeof(*lnk));
  // Dummy node
  lnk->item = 0.0;
  lnk->next = NULL;

  return lnk;
}

link insert(link list, double d) {
  link l = malloc(sizeof(*l));
  l->item = d;
  l->next = list->next;
  list->next = l;

  return list;
}

int removeMin(link list) {
  if(list->next == NULL) {
    return -1.0;
  }
  double min = list->next->item;
  link chosen = list->next;
  link prev = list->next;
  link follower = list->next;
  link current = list->next->next;

  while(current != NULL) {
    if(current->item <= min) { // make sure to take the older if equal
      min = current->item;
      chosen = current;
      prev = follower;
    }
    follower = current;
    current = current->next;
  }
  if(chosen != list->next) {
    prev->next = chosen->next;
  } else {
    list->next = chosen->next;
  }
  free(chosen);

  return min;
}
