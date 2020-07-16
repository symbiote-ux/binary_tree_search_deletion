#include "binary_search.h"

void print_in_order(Node_ptr tree) {
  if (tree == NULL) return;
  print_in_order(tree->left);
  printf("%d\n",tree->value);
  print_in_order(tree->right);
};

void print_pre_order(Node_ptr tree) {
  if (tree == NULL) return;
  printf("%d\n",tree->value);
  print_pre_order(tree->left);
  print_pre_order(tree->right);
};

void print_post_order(Node_ptr tree) {
  if (tree == NULL) return;
  print_post_order(tree->left);
  print_post_order(tree->right);
  printf("%d\n",tree->value);
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

int main(void) {
  Node_ptr tree = insert(NULL,5);
  insert(tree,10);
  insert(tree,2);
  insert(tree,5);
  print_in_order(tree);
  bool result = binary_search_tree(tree,10);
  printf("Is Present: %d\n",result);
  return 0;
};
