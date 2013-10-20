#ifndef _BST_INCLUDED
#define _BST_INCLUDED

#define PREORDER   -1
#define INORDER     0
#define POSTORDER   1

typedef struct bst bst_t;

/* function prototypes */
void *bst_search(bst_t *root, void *key, int (*cmp)(void *, void *));
bst_t *bst_insert(bst_t *root, void *val, int (*cmp)(void *, void *));
bst_t *bst_remove(bst_t *root, void *val, void **valptr, int (*cmp)(void *, void *));
void bst_visit(bst_t *root, int way, void (*process)(void *, void *), void *ptr);
void bst_print(bst_t *root, void (*print)(void *, FILE *), FILE *fp);
void bst_free(bst_t *root, void (*quit)(void *));

#endif
