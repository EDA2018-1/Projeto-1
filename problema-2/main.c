#include <stdio.h>

int *recebe_notas(float *, int *, int);

int main(int argc, char const *argv[]) {
  int num_elementos = 10;
  float notas[num_elementos];
  int apr[num_elementos];
  int i = 0, *p;

/*
  for(i = 0; i<num_elementos; i++){
    scanf("%f", &notas[i]);
  }
*/
  p = recebe_notas(notas, apr, num_elementos);

/*
  for(i = 0; i<num_elementos; i++){
    printf("%d\n", *(p+i));
  }
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
