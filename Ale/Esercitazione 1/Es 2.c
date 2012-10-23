#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float x, y, z, totx=0, toty=0, totz=0;
    int i = 0;

    FILE *file;
    while(feof(file)==0)
    {
     if ((file = fopen ("punti.txt", "r"))== NULL)
     {
         printf ("Il file non puo' essere aperto!");
         exit(1);
     }
        else
        {
            fscanf (file, "%f%f%f", &x, &y, &z);

            totx += x;
            toty += y;
            totz += z;
            i++;
            }
       }
    fclose(file);

    x = totx / i;
    y = toty / i;
    z = totz / i;

    printf ("Le coordinate del baricentro sono: %f %f %f", x, y, z);

return 0;

}
