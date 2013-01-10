#include <stdio.h>
#include "utility.h"

int find(void*haystack, int n, int s, void* needle, int (*cmp)(void*, void*)){
  char*_vect = (char*)haystack + n * s;
	while(n > 0){
		_vect -= s;
		n--;
		if(cmp((void*)_vect, needle) == 0)
			return n;
	}
	return -1;
}
