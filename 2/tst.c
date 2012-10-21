/*
	Script per generare i test.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	int maxLen, r=0, i, j, per;
	FILE *test = fopen("test.dat", "w");
	char *s;
	if(argc < 2)
		return -1;
	maxLen = atoi(argv[1]);
	s = malloc(maxLen);
	memset(s, 'a', maxLen);
	for(r = argc > 2 ? atoi(argv[2]) : 3; r; r--)
		for(i = 1; i <= maxLen; i++){
			per = rand() % i;
			if(per == 0)
				fwrite(s, 1, i, test);
			else{
					for(j = per; j <= i; j+=per){
						fwrite(s, 1, per-1, test);
						fputc('0', test);
					}
				j -= per;
				if(j < i){
					fwrite(s, 1, i-j, test);
				}
			}
			fputc('\n', test);
		}
	return 0;
}
