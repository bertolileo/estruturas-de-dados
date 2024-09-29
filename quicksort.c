#include<stdio.h>
#include<stdlib.h>
#include <time.h>


particione(int *A, int inicio, int fim){
    int pivo = (A[inicio] + A[fim] + A[(inicio + fim)/2]) / 3;
    while (inicio < fim){
        while (inicio < fim && A[inicio] <= pivo)
            inicio++;
        while (inicio < fim && A[fim] > pivo)
            fim--;
        swap(A, inicio, fim);
    }
    return inicio;
}


quick_sort(int *A, int inicio, int fim){
    if (inicio < fim){
        int piv = particione(A, inicio, fim);
        quick_sort(A, inicio, piv-1);
        quick_sort(A, piv, fim);
    }
}

void swap (int *A, int i, int j) {
  int t = A[i];
  A[i] = A[j];
  A[j] = t;
}

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
    quick_sort(A, 0, n-1);
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
