typedef struct node* link;
struct node {
  int item;
  link next;
};

link init();
link insert();
int remove();
