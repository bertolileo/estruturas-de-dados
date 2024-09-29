#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertion_sort_recursive(int *A, int n){
    if (n > 1){
        printf("a\n");
        insertion_sort(A, n-1);
        int j = n-2;
        int key = A[n-1];
        while (j > 0 && (A[j] > key)){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }

}

/* */
void insertion_sort (int *A, int n) {
  int i, j, aux, key;
  for (i = 1; i < n; i++){
    key = A[i];
    j = i-1;
    while (j >= 0 && (A[j] > key)) {
            A[j+1] = A[j];
            j--;
    }
    A[j+1] = key;
  }
}

// Função para imprimir o array
void print_array(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int n = 10;

    // Alocar memória para o array
    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    // Inicializar o gerador de números aleatórios
    srand(time(NULL));

    // Preencher o array com números aleatórios
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
    }

    printf("Array original: \n");
    print_array(A, n);

    // Medir o tempo de execução do insertion_sort
    clock_t start = clock();
    insertion_sort_recursive(A, n);
    clock_t end = clock();

    printf("Array ordenado: \n");
    print_array(A, n);

    // Calcular o tempo de execução em segundos
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do insertion_sort: %f segundos\n", time_taken);

    // Liberar a memória alocada
    free(A);

    return 0;
}
