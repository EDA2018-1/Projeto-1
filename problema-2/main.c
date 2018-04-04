#include <stdio.h>

int *recebe_notas(float *, int *, int);
void *conta_nota(int *, int, int *);
int percent_aprov(int *, float *);
int main(int argc, char const *argv[]) {
  int num_elementos = 10;
  float notas[num_elementos];
  int apr[num_elementos], resultado[2] = {0,0};
  int i = 0, *p, *q, r;
  float percent_resultado[2] = {0,0};

  for(i = 0; i<num_elementos; i++){
    scanf("%f", &notas[i]);
  }
  p = recebe_notas(notas, apr, num_elementos);
  conta_nota(apr, num_elementos, resultado);
  r = percent_aprov(resultado, percent_resultado);
  printf("Quantidade de aprovados: %d\n", *(resultado));
  printf("Quantidade de reprovados: %d\n", *(resultado+1));
  printf("Quantidade de aprovados: %.2f\n", *(percent_resultado));
  printf("Quantidade de reprovados: %.2f\n", *(percent_resultado+1));
  if (r==1)
    printf("Mais da metade da turma aprovada\n");
  else
    printf("Metade ou mais da turma reprovada\n" );
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
void *conta_nota(int *apr, int num_elementos, int *resultado){
  int i =0;
  for(i=0;i<num_elementos;i++){
    if(*(apr+i)==1)
      *resultado+=1;
    else
      *(resultado+1) += 1;
  }
}
int percent_aprov (int *resultado, float *percent_resultado){
  int i=0, num_total;
  *percent_resultado = (*resultado)*10;
  *(percent_resultado+1) = (*(resultado+1))*10;
  if (*(percent_resultado)>50)
    return 1;
  else
    return 0;
}
