#include <stdio.h>
#include <stdlib.h>
#include <time.h>


counting_sort(int *A, int n, int max){
    int i, j;
    int *T = (int *)malloc(n * sizeof(int)); /*temporário*/
    int *C = (int *)malloc((max+1) * sizeof(int)); /*contador*/

    for(i = 0; i <= max; i++)
        C[i] = 0;
    for(i = 0; i < n; i++)
        C[A[i]]++;
    for(i = 1; i <= max; i++)
        C[i] += C[i-1];

    for(j = n-1; j >= 0; j--){
        T[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
    for(i = 0; i < n; i++)
        A[i] = T[i];

    free(T);
    free(C);
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
    int aux[n];

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
        A[i] = rand() % 11; // Gera números aleatórios entre 0 e 99
    }

    printf("Array original: \n");
    print_array(A, n);

    // Medir o tempo de execução do insertion_sort
    clock_t start = clock();
    counting_sort(A, n, 10);
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
