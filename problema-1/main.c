#include <stdio.h>

void fneuronio(float *, float *, float, int, int *);

int main(int argc, char const *argv[]) {

  int i = 0, x, num_max = 10;
  float entradas[num_max], pesos[num_max], limiar;
  int* estado_neuronio = &x;

  printf("Digite 10 entradas: \n");
  for(i = 0; i < num_max; i++){
    printf("Digite sua %dº entrada: \n", i+1);

    scanf("%f", &entradas[i]);
  }

  printf("Digite o peso de cada entrada: \n");
  for(i = 0; i < num_max; i++){
    printf("peso da %dº entrada: \n", i+1);

    scanf("%f", &pesos[i]);
  }

  printf("Digite o limiar de excitação do neurônio: \n");
  scanf("%f", &limiar);

  fneuronio(entradas, pesos, limiar , num_max, estado_neuronio);

  if(*estado_neuronio==1)
    printf("Neurônio ativado!\n");
  else
    printf("Neurônio inibido!\n");

  return 0;
}

void fneuronio(float *n, float *m, float t, int num_max, int *estado_neuronio){
  int i = 0;
  float somap = 0;
  for(i=0; i < num_max; i++){
    somap += (*n + i) * (*m + i);
  }
  if(somap > t){
    *estado_neuronio = 1;
  }
  else{
    *estado_neuronio = 0;
  }
}
