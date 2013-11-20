#include <stdlib.h>
#include <stdio.h>

int main(int argc, char**argv)
{

	double R1, R2;
	int i;

	if(argc < 2) {
		printf("utilizzo: parall R1 [R2] [R3] ...\n");
		return;
	}

	R2=atof(argv[1]);
	for(i=2; i < argc;i++){
		R1=atof(argv[i]);
		R2=(R1*R2)/(R1+R2);
	}
	printf("%f\n",R2);
	return 0;
}
