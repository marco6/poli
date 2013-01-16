/**CHeaderFile*****************************************************************

  FileName    [heap.h]

  PackageName []

  Synopsis    [Header file for the "index heap" data structure]

  Description []

  SeeAlso     []  

  Author      [Sergio Nocco]

  Copyright   []
  
  Revision    []

******************************************************************************/

#ifndef _HEAP
#define _HEAP

/*---------------------------------------------------------------------------*/
/* Nested includes                                                           */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*---------------------------------------------------------------------------*/
/* Constant declarations                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Enum declarations                                                         */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/

typedef struct heap_s heap_t;

/*---------------------------------------------------------------------------*/
/* Structure declarations                                                    */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Variable declarations                                                     */
/*---------------------------------------------------------------------------*/
 
/*---------------------------------------------------------------------------*/
/* Macro declarations                                                        */
/*---------------------------------------------------------------------------*/
        
/**Macro***********************************************************************
  Synopsis    [Heap macros.]
  Description [.]
  SideEffects []
******************************************************************************/

#define heap_fix(hp, idx) (void)(heap_fix_up(hp, idx), heap_fix_down(hp, idx))

/**AutomaticStart*************************************************************/

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

extern heap_t *heap_alloc(void *array, int dim, int (*cmp)(void *lv, void *rv), int elem_size);
extern heap_t *heap_make(void *array, int dim, int (*cmp)(void *lv, void *rv), int elem_size);
extern void heap_insert(heap_t *hp, int idx);
extern int heap_remove(heap_t *hp, int idx);
extern void heap_fix_up(heap_t *hp, int idx);
extern void heap_fix_down(heap_t *hp, int idx);
extern heap_t *heap_free(heap_t *hp);
extern int heap_extract(heap_t *hp);
extern int heap_is_empty(heap_t *hp);
extern int is_in_heap(heap_t *hp, int idx);

/**AutomaticEnd***************************************************************/

#endif 
