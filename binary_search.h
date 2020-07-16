#include <stdlib.h>
#include <stdio.h>

typedef enum {
  False,
  True
} bool;

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

void print_in_order(Node_ptr tree);
Node_ptr create_node(int value);
Node_ptr insert(Node_ptr tree,int value);
bool binary_search_tree(Node_ptr tree, int value);