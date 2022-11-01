#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define INI 1
#define MX 100

void preencherVetor(int *, int, int, int);
void imprimirVetor(int *, int);
void interVetor(int *, int *, int *, int, int);
void tiraRepeticao(int *, int);
void bubblesort(int *, int);
void tamanhoPont(int *, int *, int, int, int*);
int atualizarTamanho(int *, int);

int main(int argc, char *argv[]) {
  int *pa = NULL, *pb = NULL, *pc = NULL, *qnt = NULL;
  int a, b;

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  srand(time(NULL));

  if (!(pa = malloc(a * sizeof(int)))) {
    exit(1);
  }
  if (!(pb = malloc(b * sizeof(int)))) {
    exit(2);
  }
  if (!(qnt = malloc(1 * sizeof(int)))) {
    exit(3);
  }

  preencherVetor(pa, a, INI, MX);
  preencherVetor(pb, b, INI, MX);
  printf("\n");

  bubblesort(pa, a);
  bubblesort(pb, b);

  imprimirVetor(pa, a);
  printf("\n");
  imprimirVetor(pb, b);

  tiraRepeticao(pa, a);
  tiraRepeticao(pb, b);
  
  int novoA = atualizarTamanho(pa, a);
  printf("\n\nTAMANHO NOVO VETOR 1: %d", novoA);
  int novoB = atualizarTamanho(pb, b);
  printf("\nTAMANHO NOVO VETOR 2: %d", novoB);

  sleep(1);

  tamanhoPont(pa, pb, novoA, novoB, qnt);
  printf("\n\nTamanho da intersecção: %d\n", *qnt);
  

if (!(pc = malloc(*qnt * sizeof(int)))) {
  exit(3);
}
sleep(1);

interVetor(pa, pb, pc, novoA, novoB);

printf("\nVetor da intersecção A ∩ B:\n\n");
imprimirVetor(pc, *qnt);
return 0;
}

void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa) {

  for (int k = 0; k < qtd; k++) {
    *(pd + k) = inicial + rand() % qtdFaixa;
  }
}

void imprimirVetor(int *pd, int qtd) {
  for (int k = 0; k < qtd; k++) {
    printf("[%p] %d\n", pd + k, *(pd + k));
  }
}

void bubblesort(int *vet, int tam) {
  for (int i = 0; i < tam - 1; i++) {
    for (int j = i + 1; j < tam; j++) {
      if (*(vet + j) < *(vet + i)) {
        *(vet + i) ^= *(vet + j);
        *(vet + j) ^= *(vet + i);
        *(vet + i) ^= *(vet + j);
      }
    }
  }
}

void tamanhoPont(int *pa, int *pb, int a, int b, int *qnt) {
  int i, j;
  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      if (*(pa + i) == *(pb + j)) {
       *qnt = *qnt + 1;
      }
    }
  }
}

void interVetor(int *vet1, int *vet2, int *vet3, int a, int b) {
  int k = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (*(vet1 + i) == *(vet2 + j)) {
        *(vet3 + k) = *(vet2 + j);
        k++;
      }
    }
  }
}

void tiraRepeticao(int *pd, int tam) {
  int i, j, k;

  // Remove valores duplicados //
  for (i = 0; i < tam; i++) {
    for (j = i + 1; j < tam;) {
      if (*(pd + j) == *(pd + i)) {
        for (k = j; k < tam; k++)
          *(pd + k) = *(pd + k + 1);
        tam--;
      } else {
        j++;
      }
    }
  }
  // Ponteiro após remoção de duplicatas //
  printf("\nSem repetições: ");
  for (i = 0; i < tam; i++) {
    printf("%d ", *(pd + i));
  }
}

int atualizarTamanho(int *pd, int tam){
  int i, j, k;

  // Remove valores duplicados //
  for (i = 0; i < tam; i++) {
    for (j = i + 1; j < tam;) {
      if (*(pd + j) == *(pd + i)) {
        for (k = j; k < tam; k++)
          *(pd + k) = *(pd + k + 1);
        tam--;
      } else {
        j++;
      }
    }
  }
  return tam-1;
}
