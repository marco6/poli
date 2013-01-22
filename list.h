#ifndef _LIST_INCLUDED
#define _LIST_INCLUDED

typedef struct list list_t;

#define list_is_empty(lp) (list_num(lp) == 0) 

list_t *list_alloc(void);
int list_num(list_t *);
int list_insert(list_t *, void *);
void *list_remove(list_t *, void *, int (*cmp)(void *, void *));
void *list_search(list_t *, void *, int (*cmp)(void *, void *));
void list_print(list_t *, FILE *, void (*print)(void *, FILE *));
void list_traverse(list_t *, void *, void (*elaborate)(void *, void *));
void list_free(list_t *, void (*quit)(void *));

#endif
