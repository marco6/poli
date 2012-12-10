#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _(x, y) [(y)*n + (x)]

int magic(int, int*, char*, int);

int main(int argc, char**argv) {
	clock_t t;
	int n = atoi(argv[1]),
		*mem = (int*)malloc(n * n * sizeof(int)), i, j;
	char *track = (char*)calloc(1, sizeof(char)*n*n);
	t = clock();
	if(!magic(n, mem, track, 0))
		printf("Impossibile trovare una soluzione");
	else {
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++)
				printf("%d\t", mem _(j, i));
			putchar('\n');
		}
	}
	t = clock() - t;
	printf("\n%f\n", ((float)t)/CLOCKS_PER_SEC);
	return 0;
}

int check(int n, int *mem){
	int i, j, s1, s2, tot = n * (n*n + 1) / 2;
	for(i = s1 = s2 = 0; i < n; i++){
		s1 += mem _(i, i);
		s2 += mem _(n-1-i, i);
	}
	if(s1 != tot || s2 != tot)
		return 0;
	for(j = 0; j < n; j++){
		for(i = s1 = s2 = 0; i < n; i++){
			s1 += mem _(i, j);
			s2 += mem _(j, i);
		}
		if(s1 != tot || s2 != tot)
			return 0;
	}
	return 1;
}

int magic(int n, int *mem, char*track, int i){
	int j;
	//Controlliamo di non essere in un caso terminale
	if(i >= n*n)
		//in tal caso congediamo il paziente u.u
		return check(n, mem);
	for(j = 0; j < n*n; j++){
		if(track[j]) continue;
		track[j] = 1;
		mem[i] = j + 1;
		if(magic(n, mem, track, i+1))
			return 1;
		track[j] = 0;
	}
	return 0;
}