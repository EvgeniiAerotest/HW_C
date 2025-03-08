#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct tree
{
  datatype key;
  struct tree *left;
  struct tree *right;
  struct tree *parent;
} tree;

tree *findBrother(tree *root, int key)
{
  tree *current = root;
  tree *fnode = NULL;

  while (current != NULL)
  {
    if (key == current->key)
    {
      fnode = current;
      break;
    }
    else if (key < current->key)
      current = current->left;
    else
      current = current->right;
  }
  if (fnode == NULL)
    return NULL;
  if (fnode->parent == NULL)
    return NULL;
  if (fnode->parent->left == fnode)
    return fnode->parent->right;
  else
    return fnode->parent->left;
}

int main()
{
  tree *tr = NULL;

  tr = calloc(1, sizeof(tree));
  tr->key = 3;

  tr->left = calloc(1, sizeof(tree));
  tr->left->key = 1;
  tr->left->parent = tr;

  tr->right = calloc(1, sizeof(tree));
  tr->right->key = 5;
  tr->right->parent = tr;

  tr->left->left = calloc(1, sizeof(tree));
  tr->left->left->key = 0;
  tr->left->left->parent = tr->left;

  tr->left->right = calloc(1, sizeof(tree));
  tr->left->right->key = 2;
  tr->left->right->parent = tr->left;

  tr->right->left = calloc(1, sizeof(tree));
  tr->right->left->key = 4;
  tr->right->left->parent = tr->right;

  tr->right->right = calloc(1, sizeof(tree));
  tr->right->right->key = 6;
  tr->right->right->parent = tr->right;

  tree *bro = findBrother(tr, 4);
  if (bro != NULL)
    printf("brother of node: %d\n", bro->key);
  else
    printf("no brother\n");

  return 0;
}
