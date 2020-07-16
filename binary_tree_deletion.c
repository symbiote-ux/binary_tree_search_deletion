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

void print_in_order(Node_ptr tree) {
  if (tree == NULL) return;
  print_in_order(tree->left);
  printf("%d\n",tree->value);
  print_in_order(tree->right);
};

Node_ptr create_node(int value) {
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
};

Node_ptr insert(Node_ptr tree,int value) {
  if(tree == NULL) return create_node(value);
  Node_ptr root = tree;
  while (1) {
    if (value > root->value) {
      if (root->right == NULL) {
        root->right = create_node(value);
        return tree;
      }
      root = root->right;
    } else {
      if (root->left == NULL) {
        root->left = create_node(value);
        return tree;
      }
      root = root->left;
    }
  }
};

bool binary_search_tree(Node_ptr tree, int value) {
  Node_ptr root = tree;
  while (1) {
    if (root == NULL) return False;
    if (root->value == value) return True;
    if (value > root->value) root = root->right;
    else root = root->left;
  }
};

Node_ptr get_min_tree(Node_ptr tree) {
  if (tree->left == NULL) return tree;
  return get_min_tree(tree->left);
};

Node_ptr delete_value(Node_ptr tree, int value) {
  bool isPresent = binary_search_tree(tree, value);
  if (!isPresent) return tree;
  if (tree->left == NULL && tree->right == NULL && tree->value == value) {
    return NULL;
  } 
  if (tree->value > value) {
    tree->left = delete_value(tree->left, value);
    return tree;
  }
  if (tree->value < value) {
    tree->right = delete_value(tree->right, value);
    return tree;
  }
  if (tree->right == NULL) {
    tree->value = tree->left->value;
    tree->left = delete_value(tree->left, tree->left->value);
    return tree;
  }
  Node_ptr min_tree = get_min_tree(tree->right);
  tree->value = min_tree->value;
  tree->right = delete_value(tree->right, min_tree->value);
  return tree;
};


void remove_node_from_middle() {
  Node_ptr tree = insert(NULL,5);
  insert(tree,10);
  insert(tree,5);
  insert(tree,1);
  insert(tree,8);
  insert(tree,20);
  insert(tree,25);
  insert(tree,15);
  print_in_order(tree);
  delete_value(tree, 10);
  printf("-----------------------------\n");
  print_in_order(tree);
};

void remove_single_root() {
  Node_ptr tree = insert(NULL,5);
  insert(tree,10);
  insert(tree,5);
  print_in_order(tree);
  delete_value(tree, 10);
  printf("-----------------------------\n");
  print_in_order(tree);
};

void remove_leaf() {
  Node_ptr tree = insert(NULL,5);
  insert(tree,10);
  insert(tree,2);
  insert(tree,5);
  print_in_order(tree);
  delete_value(tree, 5);
  printf("-----------------------------\n");
  print_in_order(tree);
};

int main(void) {
  remove_leaf();
  remove_single_root();
  remove_node_from_middle();
  return 0;
};
