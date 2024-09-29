#include "utils.h"

/* */
int particione(int *A, int inicio, int fim) {
    int pivo = A[inicio];
    int esq = inicio + 1;
    int dir = fim;

    while (esq <= dir) {
        while (esq <= dir && A[esq] <= pivo)
            esq++;
        while (esq <= dir && A[dir] > pivo)
            dir--;
        if (esq < dir)
            swap(A, esq, dir);
    }
    swap(A, inicio, dir); // Coloca o pivô na posição correta
    return dir;
}


// Função Quicksort iterativa
void quick_sort(int *A, int inicio, int fim) {
    // Criação de uma pilha para simular a recursão
    int pilha[fim - inicio + 1];
    int topo = -1;

    // Push inicial na pilha
    pilha[++topo] = inicio;
    pilha[++topo] = fim;

    // Enquanto a pilha não estiver vazia
    while (topo >= 0) {
        // Pop do fim e do início
        fim = pilha[topo--];
        inicio = pilha[topo--];

        // Particione o array e obtenha o índice do pivô
        int piv = particione(A, inicio, fim);

        // Se houver elementos à esquerda do pivô, os empurre na pilha
        if (piv - 1 > inicio) {
            pilha[++topo] = inicio;
            pilha[++topo] = piv - 1;
        }

        // Se houver elementos à direita do pivô, os empurre na pilha
        if (piv + 1 < fim) {
            pilha[++topo] = piv + 1;
            pilha[++topo] = fim;
        }
    }
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int n = 10; /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));
  int B[10] = {4, 7, 0, 0, 2, 0, 7, 7, 2, 6};
  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    //A[i] = 0; /*iguais*/
  }

  start = clock();
  print (A, n, "Input");
  quick_sort (A, 0, n-1);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

