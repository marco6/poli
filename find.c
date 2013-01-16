//implementazione di find

#include <algo.h>

int find(const void*haystack, size_t n, size_t s, const void *needle, int (*compare)(const void*, const void*)){
	const char*_m = (const char*)haystack;
	if(n == 0)
		return -1;
	while(n){
		_m -= s;
		if(compar(_m, needle) == 0) return n-1;
		n--;
	}
	return -1;
}