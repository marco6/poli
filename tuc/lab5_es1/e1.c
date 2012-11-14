#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binario(char *s, int cifre, int i);

int main()
{
    int cifre, i=0;
    char *s;
    scanf("%d", &cifre);
    s=(char*)malloc(cifre*sizeof(char)+1);
    s[cifre] = '\0';
    binario(s, cifre, i);
    free(s);
    return 0;
}

void binario(char *s, int cifre, int i)
{
    if(i<cifre)
    {
        s[i]='0';
        binario(s, cifre, i+1);
        s[i]='1';
        binario(s, cifre, i+1);
    }
    else printf("%s\n", s);
}
