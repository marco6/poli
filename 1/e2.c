/*
 * Laboratorio 1, eserciozio 2
 * Un file di testo contiene un numero indefinito di punti dello spazio cartesiano XYZ, 
 * ciascuno specificato in ragione di una riga del file secondo il formato seguente:
 *
 *   <x> <y> <z>
 * 
 * essendo <x>, <y> e <z> le tre coordinate del punto in questione.
 * Si scriva un programma C che, a partire dal contenuto del file suddetto, 
 * determini e visualizzi le coordinate del baricentro dell’insieme di punti 
 * in esso specificato. Si noti che il baricentro di un insieme di punti è il 
 * punto le cui coordinate sono la “media” di tutte le rispettive coordinate 
 * dell’insieme di punti stesso.
 *
 *
 * Per compilare da linea di comando si può usare:
 *			gcc -o e3 e3.c -Wall -pedantic
 */

#include <stdio.h>

#define ERR(str, n) { fprintf(stderr, str); return n; }

int main(int argc, char*argv[]){
    FILE*f;
    float x = 0,y = 0,z = 0, /*In questi piazzo la somma*/
		a,b,c; /* Questi li do in pasto alla scanf */
    unsigned int r = 0;/*Qui memorizzo il numero di righe */
    char line[128];
    if(argc < 2)
        ERR("Devi specificare un file!!!", 1)
    if(!(f=fopen(argv[1], "r")))
        ERR("Errore apertura file :(", 2)
    while(!feof(f)){
        if(!fgets(line, 128, f))
            continue;
        if(sscanf(line, "%f %f %f", &a, &b, &c) != 3)
            ERR("Errore formattazione del file.", 3)

		/*Qui fai la somma*/
		x += a;
        y += b;
        z += c;
        r++;
    }/* While */
    printf("Baricentro: %.1f  %.1f  %.1f", x/r, y/r, z/r);
    return 0;
}/*main*/
