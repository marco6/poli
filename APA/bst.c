#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct bst {
   void *data;
   bst_t *left;
   bst_t *right;
};

static bst_t *node_alloc(void *val);
static void *delete_min(bst_t **rootptr);
static void *delete_max(bst_t **rootptr);

void *bst_min(bst_t *root)
{
   if (root == NULL)
      return NULL;

   while (root->left != NULL)
      root = root->left;

   return root->data;
}

void *bst_max(bst_t *root)
{
   if (root == NULL)
      return NULL;

   while (root->right != NULL)
      root = root->right;

   return root->data;
}

void *bst_search(bst_t *root, void *key, int (*cmp)(void *, void *))
{
	int _cmp;
	while (root != NULL) {
		_cmp = (*cmp)(key, root->data);
		if (_cmp == 0)
			return root->data;
		if (_cmp < 0)
			root = root->left;
		else
			root = root->right;
	}
	return NULL;
}

bst_t *bst_insert(bst_t *root, void *val, int (*cmp)(void *, void *))
{
   /* empty tree */
   if (root == NULL)
      return node_alloc(val);
   
   if ((*cmp)(val, root->data) < 0) {
      /* insert left */
      root->left = bst_insert(root->left, val, cmp);
   } else {
      /* insert right */
      root->right = bst_insert(root->right, val, cmp);
   }
   return root;
}

bst_t *bst_extract_min(bst_t *root, void **valptr)
{
   bst_t *node;
   void *val;

   if (root == NULL) {
      /* empty bst */
      if (valptr != NULL)
         *valptr = NULL;
      return NULL;
   }
   if (root->left == NULL) {
      /* root is the min */
      if (valptr != NULL)
         *valptr = root->data;
      node = root->right;
      free(root);
      return node;
   }
   val = delete_min(&root->left);
   if (valptr != NULL)
      *valptr = val;
   return root;
}

bst_t *bst_extract_max(bst_t *root, void **valptr)
{
   bst_t *node;
   void *val;

   if (root == NULL) {
      /* empty bst */
      if (valptr != NULL)
         *valptr = NULL;
      return NULL;
   }
   if (root->right == NULL) {
      /* root is the max */
      if (valptr != NULL)
         *valptr = NULL;
      node = root->left;
      free(root);
      return node;
   }
   val = delete_min(&root->left);
   if (valptr != NULL)
      *valptr = val;
   return root;
}

bst_t *bst_remove(bst_t *root, void *val, void **valptr, int (*cmp)(void *, void *))
{
   bst_t *node;

   if (root == NULL) {
      if (valptr != NULL)
         *valptr = NULL;
      return NULL;
   }
   if ((*cmp)(val, root->data) < 0) {
      /* delete left */
      root->left = bst_remove(root->left, val, valptr, cmp);
      return root;
   } 

   if ((*cmp)(val, root->data) > 0) {
      /* delete right */
      root->right = bst_remove(root->right, val, valptr, cmp);
      return root;
   }

   /* delete this node */
   if (valptr != NULL)
      *valptr = root->data;
   if (root->right == NULL) {
      node = root->left;
      free(root);
      return node;
   }
   if (root->left == NULL) {
      node = root->right;
      free(root);
      return node;
   }
   /* two children: delete the successor */
   root->data = delete_min(&root->right);
   return root;
}

void bst_visit(bst_t *root, int way, void (*visit)(void *, void *), void *ptr)
{
   if (root == NULL)
      return;

   if (way == PREORDER) 
      (*visit)(root->data, ptr);

   bst_visit(root->left, way, visit, ptr);

   if (way == INORDER) 
      (*visit)(root->data, ptr);

   bst_visit(root->right, way, visit, ptr);

   if (way == POSTORDER) 
      (*visit)(root->data, ptr);
}

void bst_print(bst_t *root, void (*print)(void *, FILE *), FILE *fp)
{
   if (root == NULL)
      return;

   bst_print(root->left, print, fp);
   (*print)(root->data, fp);
   bst_print(root->right, print, fp);
}

void bst_free(bst_t *root, void (*quit)(void *))
{
   if (root == NULL)
      return;

   bst_free(root->left, quit);
   bst_free(root->right, quit);
   if (quit != NULL)
      (*quit)(root->data);
   free(root);
}

static bst_t *node_alloc(void *val)
{
  bst_t *node;

  node = (bst_t *)malloc(sizeof(bst_t));
  if (node == NULL) {
    printf("Error while allocating memory ...\n");
    exit(1);
  }

  node->data = val;
  node->left = node->right = NULL;
  return node;
}

static void *delete_min(bst_t **rootptr)
{
   bst_t *node;
   void *val;

   while ((*rootptr)->left != NULL)
      rootptr = &((*rootptr)->left);

   node = *rootptr;
   val = node->data;
   *rootptr = (*rootptr)->right;
   free(node);

   return val;
}

static void *delete_max(bst_t **rootptr)
{
   bst_t *node;
   void *val;

   while ((*rootptr)->right != NULL)
      rootptr = &((*rootptr)->right);

   node = *rootptr;
   val = node->data;
   *rootptr = (*rootptr)->left;
   free(node);

   return val;
}
