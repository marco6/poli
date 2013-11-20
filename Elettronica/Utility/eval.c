#include <stdio.h>
#include <string.h>
#include <math.h>

enum err {
  none = 0,
  empty = 1,
  badformat = 2,
  parmismatch = 3
} error = none;

double eval(const char*c);

int main(int argc, char *argv[]) {
  int i;
  static const char* errs [] = {
    "Stringa vuota",
    "Errore di formattazione",
    "Errore di parentesizzazione"
  }; 
  if(argc < 2) {
    printf("Utilizzo:\n\teval expression1 [expression2 [...] ]\n");
    return 0;
  }
  for(i = 1; i<argc; i++){
    printf("%s = %lf\n", argv[i], eval(argv[i]));
    if(error){
      printf("Errore nell'argomento %d: %d %s\n", i, (int)error, errs[(int)error-1]); 
      error = none;
    }
  }
  return 0;
}

const char* bracket(const char*c, double*res){
  static double tmp;
  double larg = 0;
  int n;
  /* gli spazi non interessano.. */
  while(*c == ' ')
    c++;
  /* Controllo che non sia una parentesi */
  if(*c == '(' || *c == '[' || *c == '{')
    c = bracket(c+1, &larg);
  /* Se non è una parentesi allora deve essere un numero che ora decodifico */
  else if(!sscanf(c, "%lf%n", &larg, &n)){
    /* non un numero? MALE! */
    error = badformat;
    return NULL;
  }
  else 
    c += n;
  
  /* fino alla fine! */
  while(*c != '}' && *c != ']' && *c != ')' && *c != '\0' && error == none){
    /* E ora ci dovrebbe essere un operatore... */
    while(*c == ' ')
      c++;

    switch(*c) {
    case '|':
      c++;
      while(*c == ' ') c++;

      if(*c == '(' || *c == '[' || *c == '{')
	c = bracket(c+1, &tmp);
      else if(!sscanf(c, "%lf%n", &tmp, &n)){
	/* non un numero? MALE! */
	error = badformat;
	return 0;
      }
      else
	c +=n;

      puts(c);
      larg = larg * tmp / (fabs(larg) + tmp);
      break;
    case '+':
      c = bracket(c+1, &tmp);
      *res = larg + tmp;
      return c;
    case '-':
      c = bracket(c+1, &tmp);
      *res = larg - tmp;
      return c;
    default:
      error = badformat;
    }
  }
  if(*c == '\0')
    error = parmismatch;
  *res = larg;
  return c+1;
}

double eval(const char*c) {
  static double tmp;
  double larg = 0;
  int n;
  if(c == NULL)
    return 0;
  while(*c == ' ')
    c++;
  if(*c == '(' || *c == '[' || *c == '{')
    c = bracket(c+1, &larg);
  else if(!sscanf(c, "%lf%n", &larg, &n)){
    error = badformat;
    return 0;
  }
  else
    c += n;

  while(*c != '\0' && error == none){
    while(*c == ' ')
      c++;
    switch(*c) {
    case '|':
      c++;
      while(*c == ' ') c++;

      if(*c == '(' || *c == '[' || *c == '{')
	c = bracket(c+1, &tmp);
      else if(!sscanf(c, "%lf%n", &tmp, &n)){
	error = badformat;
	return 0;
      }
      else
	c += n;

      larg = larg * tmp / (fabs(larg) + tmp);
      break;
    case '+':
      return larg + eval(c+1);
    case '-':
      return larg - eval(c+1);
    default:
      error = badformat;
    }
  }
  return larg;
}
 
