#include <stdlib.h>
#include "coda.h"

static Item *q;
static int N, head, tail;

void new_(int maxN)
{
  q = malloc((maxN+1)*sizeof(Item));
  N = maxN+1;
  head = N;
  tail = 0;
}

int vuota()
{
  return head%N == tail;
}

void insert(Item item)
{
  q[tail++] = item;
  tail = tail%N;
}

Item extract()
{
  head = head%N;
  return q[head++];
}






