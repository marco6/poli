#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
  void    *data;
  stack_t *next;
};

static stack_t *node_alloc(void *val);

void stack_free(stack_t *sp, void (*free_function)(void *))
{
  stack_t *node = sp;

  while (node != NULL) {
     sp = node->next;
     if (free_function != NULL)
        (*free_function)(node->data);
     free(node);
     node = sp;
  }
}

stack_t *stack_push(stack_t *sp, void *val)
{
  stack_t *node = node_alloc(val);

  node->next = sp;
  return node;
}

stack_t *stack_pop(stack_t *sp, void **valptr)
{
  stack_t *node = sp;

  if (sp == NULL)
     return NULL;

  *valptr = sp->data;
  sp = sp->next;
  free(node);
  return sp;
}

static stack_t *node_alloc(void *val)
{
  stack_t *node;

  node = (stack_t *)malloc(sizeof(stack_t));
  if (node == NULL) {
    printf("Error while allocating memory ...\n");
    exit(1);
  }

  node->data = val;
  node->next = NULL;
  return node;
}
