#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da função bubble_sort
void bubble_sort(int *A, int n) {
    int aux, i;
    int continua;
    do {
        continua = 0;
        for (i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) {
                continua = 1;
                aux = A[i];
                A[i] = A[i + 1];
                A[i + 1] = aux;
            }
        }
        n--;
    } while (continua);
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
    int n = 30000;

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

    // Medir o tempo de execucao do bubble_sort
    clock_t start = clock();
    bubble_sort(A, n);
    clock_t end = clock();

    printf("Array ordenado: \n");
    print_array(A, n);

    // Calcular o tempo de execução em segundos
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do bubble_sort: %f segundos\n", time_taken);

    // Liberar a memória alocada
    free(A);

    return 0;
}
