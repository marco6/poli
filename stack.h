#ifndef _STACK_INCLUDED
#define _STACK_INCLUDED

typedef struct stack stack_t;

void stack_free(stack_t *sp, void (*free_function)(void *));
stack_t *stack_push(stack_t *sp, void *val);
stack_t *stack_pop(stack_t *sp, void **valptr);

#endif
