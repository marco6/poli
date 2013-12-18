#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 100
#define QS_TYPE int
#define QS_COMPARE(a,b) ((a)-(b))


void* ordina(void* args);
void QuickSort(QS_TYPE *list, int beg, int end);

typedef struct Files{
  char *nome_r;
  char *nome_w;
}files;

int main(int argc, char** argv){
 
  char *pointer;
  files *args;
  int tot, i;
  pthread_t *tid;

  tot=atoi(argv[3]);
  args=malloc(sizeof(files)*tot);
  tid=malloc(sizeof(pthread_t)*tot);

  for(i=0;i<tot;i++){
    args[i].nome_r=malloc(sizeof(char)*N);
    strcpy(args[i].nome_r,argv[1]);
    pointer=strchr(args[i].nome_r,'\0');
    sprintf(pointer,"%d.txt",i+1);

    args[i].nome_w=malloc(sizeof(char)*N);
    strcpy(args[i].nome_w,argv[2]);
    pointer=strchr(args[i].nome_w,'\0');
    sprintf(pointer,"%d.txt",i+1);

    pthread_create(&tid[i],NULL,ordina,(void*) &args[i]);
  }
  
  for(i=0; i<tot; i++){
    pthread_join(tid[i], NULL);
    free(args[i].nome_r);
    free(args[i].nome_w);
  }

  free(args);
  free(tid);
  
  return 0;
}

void* ordina(void* args){
  int* vett;
  int n, i;
  FILE *f_r, *f_w;

  f_r=fopen(((files*)args)->nome_r,"r");
  f_w=fopen(((files*)args)->nome_w,"w");
  fscanf(f_r,"%d",&n);
  vett=malloc(sizeof(int)*n);
  for(i=0;i<n;i++) fscanf(f_r,"%d",&vett[i]);
  
  QuickSort(vett,0,n-1);

  for(i=0;i<n;i++) fprintf(f_w,"%d\n",vett[i]);
  free(vett);
  fclose(f_r);
  fclose(f_w);
  pthread_exit(NULL);
}

void QuickSort(QS_TYPE *list, int beg, int end)
{
  QS_TYPE piv; QS_TYPE tmp;
  int  l,r,p;

  while (beg<end){
    l = beg; p = (beg+end)/2; r = end;
    piv = list[p];

    while (1){
      while ( (l<=r) && ( QS_COMPARE(list[l],piv) <= 0 ) ) l++;
      while ( (l<=r) && ( QS_COMPARE(list[r],piv)  > 0 ) ) r--;
      if (l>r) break;
      tmp=list[l]; list[l]=list[r]; list[r]=tmp;
      if (p==r) p=l;
      l++; r--;
    }
    list[p]=list[r]; list[r]=piv;
    r--;

    if ((r-beg)<(end-l)){
      QuickSort(list, beg, r);
      beg=l;
    }
    else{
      QuickSort(list, l, end);
      end=r;
    }
  }   
}
