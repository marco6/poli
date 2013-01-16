/**CFile*****************************************************************

  FileName    [heap.c]

  PackageName []

  Synopsis    [Implementation file for the "index heap" data structure.]

  Description []

  SeeAlso     []  

  Author      [Sergio Nocco]

  Copyright   []
  
  Revision    []

******************************************************************************/

#include "heap.h"

/*---------------------------------------------------------------------------*/
/* Constant declarations                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Stucture declarations                                                     */
/*---------------------------------------------------------------------------*/

struct heap_s {
  void *data;    /* data source array */
  int num;       /* number of data in the heap */
  int size;      /* max number of data in the heap */
  int elem_size; /* size of each element of the data array */
  int (*cmp)(void *lv, void *rv); /* priority comparison function */
  int *qp;       /* from array indices to heap positions */
  int *pq;       /* from heap positions to array indices */
};

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Variable declarations                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Macro declarations                                                        */
/*---------------------------------------------------------------------------*/

#define heap_parent(idx) \
   (((idx) - 1) / 2)

#define heap_left(idx) \
   (2 * (idx) + 1)

#define heap_right(idx) \
   (2 * (idx) + 2)

/**AutomaticStart*************************************************************/

/*---------------------------------------------------------------------------*/
/* Static function prototypes                                                */
/*---------------------------------------------------------------------------*/

/**AutomaticEnd***************************************************************/

/*---------------------------------------------------------------------------*/
/* Definition of exported functions                                          */
/*---------------------------------------------------------------------------*/


/**Function********************************************************************
  Synopsis           [Allocate a heap.]
  Description        [Allocate a heap: heap elements are given by an array.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
heap_t *
heap_alloc (
  void *array,
  int dim,
  int (*cmp)(void *lv, void *rv),
  int elem_size
)
{
  heap_t *hp;
  int i;

  assert((hp = (heap_t *)malloc(sizeof(heap_t))));
  assert((hp->qp = (int *)malloc(dim*sizeof(int))));
  assert((hp->pq = (int *)malloc(dim*sizeof(int))));
  hp->data = array;
  hp->size = dim;
  hp->num = 0;
  hp->cmp = cmp;
  hp->elem_size = elem_size;
  for (i=0; i<hp->size; i++) {
    hp->pq[i] = hp->qp[i] = -1;
  }

  return hp;
}


/**Function********************************************************************
  Synopsis           [Initialize a heap.]
  Description        [Initialize a heap: heap elements are given by an array.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
heap_t *
heap_make (
  void *array,
  int dim,
  int (*cmp)(void *lv, void *rv),
  int elem_size
)
{
  heap_t *hp;
  int i;

  assert((hp = (heap_t *)malloc(sizeof(heap_t))));
  assert((hp->qp = (int *)malloc(dim*sizeof(int))));
  assert((hp->pq = (int *)malloc(dim*sizeof(int))));
  hp->data = array;
  hp->cmp = cmp;
  hp->num = hp->size = dim;
  hp->elem_size = elem_size; 
  for (i=0; i<dim; i++) {
    hp->pq[i] = hp->qp[i] = i;
  }
  for (i=dim/2; i>=0; i--) {
    heap_fix_down(hp, i);
  }

  return hp;
}


/**Function********************************************************************
  Synopsis           [Insert a value in the heap.]
  Description        [Insert a value in the heap.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
void
heap_insert (
  heap_t *hp,
  int idx
)
{
  assert(hp->qp[idx]<0);
  hp->qp[idx] = hp->num;
  hp->pq[hp->num++] = idx;
  heap_fix_up(hp, idx);
}


/**Function********************************************************************
  Synopsis           [Remove a heap element.]
  Description        [Remove a heap element.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
int
heap_remove (
  heap_t *hp,
  int idx
)
{
  int i, pos=hp->qp[idx];
  void *iv, *xv;

  assert(pos >= 0);
  i = hp->pq[--hp->num];
  hp->pq[pos] = i;
  hp->qp[i] = pos;
  hp->qp[idx] = -1;

  if (hp->num>1 && i!=idx) {
    iv = hp->data + hp->elem_size * i;
    xv = hp->data + hp->elem_size * idx;
    if ((*hp->cmp)(iv, xv) > 0) {
      heap_fix_up(hp, i);
    } else {
      heap_fix_down(hp, i);
    }
  }
  return idx;
}


/**Function********************************************************************
  Synopsis           [Remove the highest priority heap element.]
  Description        [Remove the highest priority heap element.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
int
heap_extract (
  heap_t *hp
)
{
  return heap_remove(hp, hp->pq[0]);
}

/**Function********************************************************************
  Synopsis           [.]
  Description        [.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
void
heap_fix_up (
  heap_t *hp,
  int idx
)
{
  int *qp=hp->qp, *pq=hp->pq;
  int i=qp[idx], p=heap_parent(i), t;
  void *iv, *pv;

  while (i > 0) {
    iv = hp->data + hp->elem_size * pq[i];
    pv = hp->data + hp->elem_size * pq[p];
    if ((*hp->cmp)(iv, pv) <= 0) {
      return;
    }
    t = pq[i]; pq[i] = pq[p]; pq[p] = t;
    qp[pq[i]] = i; qp[pq[p]] = p;
    i = p; p = heap_parent(p);
  }
}


/**Function********************************************************************
  Synopsis           [.]
  Description        [.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
void
heap_fix_down (
  heap_t *hp,
  int idx
)
{
  int *qp=hp->qp, *pq=hp->pq;
  int i=hp->qp[idx], l, p, r, t;
  void *iv, *lv, *rv;

  do {
    p = i; l = heap_left(i); r = heap_right(i);
    iv = hp->data + hp->elem_size * pq[i];
    if (l < hp->num) {
      lv = hp->data + hp->elem_size * pq[l];
      if ((*hp->cmp)(lv, iv) > 0) {
        i = l; iv = lv;
      }
    }
    if (r < hp->num) {
      rv = hp->data + hp->elem_size * pq[r];
      if ((*hp->cmp)(rv, iv) > 0) {
        i = r; iv = rv;
      }
    }
    if (i != p) {
      t = pq[i]; pq[i] = pq[p]; pq[p] = t;
      qp[pq[i]] = i, qp[pq[p]] = p;
    }
  } while (i != p);
}


/**Function********************************************************************
  Synopsis           [Check whether the heap is empty.]
  Description        [Check whether the heap is empty.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
int
heap_is_empty (
  heap_t *hp
)
{
  return !hp->num;
}

/**Function********************************************************************
  Synopsis           [Check whether an array element is in the heap.]
  Description        [Check whether an array element is in the heap.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
int
is_in_heap (
  heap_t *hp,
  int idx
)
{
  return hp->qp[idx] >= 0;
}

/**Function********************************************************************
  Synopsis           [Free a heap.]
  Description        [Free a heap.]
  SideEffects        []
  SeeAlso            []
******************************************************************************/
heap_t *
heap_free (
  heap_t *hp
)
{
  if (hp) {
    free(hp->qp);
    free(hp->pq);
    /* internal data array NOT freed */
    free(hp);
  }
  return NULL;
}


/*---------------------------------------------------------------------------*/
/* Definition of internal functions                                          */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Definition of static functions                                            */
/*---------------------------------------------------------------------------*/

