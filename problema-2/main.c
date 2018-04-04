#include <stdio.h>

int *recebe_notas(float *, int *, int);
int *conta_nota(int *, int, int *);
int main(int argc, char const *argv[]) {
  int num_elementos = 10;
  float notas[num_elementos];
  int apr[num_elementos], resultado[2] = {0,0};
  int i = 0, *p, *q;

  for(i = 0; i<num_elementos; i++){
    scanf("%f", &notas[i]);
  }
  p = recebe_notas(notas, apr, num_elementos);
  q = conta_nota(apr, num_elementos, resultado);
  /*printf("%d\n", *(q));
  printf("%d\n", *(q+1));
  */
  return 0;
}
int *recebe_notas(float *notas, int *apr, int num_elementos){
  int i = 0;
  for(i = 0; i<num_elementos; i++){
    if (*(notas + i) >= 6.0)
      *(apr+i) = 1;
    else
      *(apr+i) = 0;
  }
  return apr;
}
int *conta_nota(int *apr, int num_elementos, int *resultado){
  int i =0;
  for(i=0;i<num_elementos;i++){
    if(*(apr+i)==1)
      *resultado+=1;
    else
      *(resultado+1) += 1;
  }
  return resultado;
}
