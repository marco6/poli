#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct listNode {
  void *data;
  struct listNode *next;
} listNode_t;

struct list {
  listNode_t *head;
  int num;
};

static listNode_t *newListNode(void *data);

list_t *list_alloc()
{
  list_t *lp = (list_t *)malloc(sizeof(list_t));
  
  if (lp != NULL) {
    lp->head = NULL;
    lp->num = 0;
  }
  return lp;
}

int list_num(list_t *lp)
{
  return (lp ? lp->num : 0);
}

int list_insert(list_t *lp, void *data)
{
  listNode_t *tmp = NULL;
  
  if (lp == NULL)
    return -1;
  
  tmp = newListNode(data);
  if (tmp == NULL)
    return 0;
  
  tmp->next = lp->head;
  lp->head = tmp;

  return ++lp->num;
}

void *list_remove(list_t *lp, void *data, int (*cmp)(void *, void *))
{
  listNode_t *prev, *succ;
  void *tmp;

  if (list_is_empty(lp))
    return NULL;
  
  prev = lp->head;
  if (cmp(prev->data, data) == 0) {
    lp->num--;
    lp->head = prev->next;
    tmp = prev->data;
    free(prev);
    return tmp;
  }

  succ = prev->next;
  while (succ != NULL) {
    if (cmp(succ->data, data) == 0) {
      lp->num--;
      prev->next = succ->next;
      tmp = succ->data;
      free(succ);
      return tmp;
    }
    prev = succ;
    succ = succ->next;
  }

  return NULL;
}

void *list_search(list_t *lp, void *data, int (*cmp)(void *, void *))
{
  listNode_t *tmp;

  if (lp == NULL)
    return NULL;
  
  tmp = lp->head;
  while (tmp != NULL) {
    if (cmp(tmp->data, data) == 0)
      return tmp->data;
    tmp = tmp->next;
  }

  return NULL;
}

void list_print(list_t *lp, FILE *fp, void (*print)(void *, FILE *))
{
  listNode_t *tmp;

  if (lp == NULL)
    return;

  tmp = lp->head;
  while (tmp != NULL) {
    print(tmp->data, fp);
    tmp = tmp->next;
  }
}

void list_traverse(list_t *lp, void *out, void (*elaborate)(void *, void *))
{
  listNode_t *tmp;

  if (lp == NULL)
    return;

  tmp = lp->head;
  while (tmp != NULL) {
    elaborate(tmp->data, out);
    tmp = tmp->next;
  }
}

void list_free(list_t *lp, void (*quit)(void *))
{
  listNode_t *tmp;

  if (lp == NULL)
    return;

  while (lp->head != NULL) {
    tmp = lp->head;
    lp->head = tmp->next;
    if (quit != NULL)
      (*quit)(tmp->data);
    free(tmp);
  }

  free(lp);
}

static listNode_t *newListNode(void *data)
{
  listNode_t *node = (listNode_t *)malloc(sizeof(listNode_t));
  
  if (node != NULL) {
    node->data = data;
    node->next = NULL;
  }
  
  return node;
}

