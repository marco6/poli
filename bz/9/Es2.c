#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a, const void*b) {
	return memcmp(b, a, sizeof(int)*4);
}

void scaleMatrix(int mat[4][4]) {
	qsort(&mat[0][0], 4, sizeof(int)*4, cmp);
}

int main(int argc, char*argv[]){
	int mat[4][4], i, *p = &mat[0][0], j;
	for(i = 0; i < 16; i++) {
		scanf("%d", p);
		++p;
	}
	scaleMatrix(mat);
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++)
			printf("%d\t", mat[i][j]);
		putchar('\n');
	}
	return 0;
}