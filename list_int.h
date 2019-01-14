typedef struct node* link;
struct node {
  int item;
  link next;
};

link init();
link insert(link list, int i);
int removeMin(link list);
