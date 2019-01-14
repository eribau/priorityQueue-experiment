typedef struct node* link;
struct node {
  double item;
  link next;
};

link init();
link insert(link list, double i);
int removeMin(link list);
