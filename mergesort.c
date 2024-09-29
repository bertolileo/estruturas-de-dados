#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void particione(int *A, int ini, int meio, int fim, int *O){
    int i = ini, k = ini, j = meio+1;
    while (i <= meio && j <= fim){
        if (A[i] < A[j])
            O[k++] = A[i++];
        else
            O[k++] = A[j++];
    }
    while(j <= fim)
        O[k++] = A[j++];
    while(i <= meio)
        O[k++] = A[i++];

    for(int x = ini; x <= fim; x++)
        A[x] = O[x];
}



void merge_sort(int *A, int ini, int fim, int *O){
    if(ini < fim){
        int meio = (ini + fim) / 2;
        merge_sort(A, ini, meio, O);
        merge_sort(A, meio+1, fim, O);
        particione(A, ini, meio, fim, O);
    }

}


void print_array(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Fun��o principal
int main() {
    int n = 10;
    int aux[n];

    // Alocar mem�ria para o array
    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Erro na aloca��o de mem�ria\n");
        return 1;
    }

    // Inicializar o gerador de n�meros aleat�rios
    srand(time(NULL));

    // Preencher o array com n�meros aleat�rios
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100; // Gera n�meros aleat�rios entre 0 e 99
    }

    printf("Array original: \n");
    print_array(A, n);

    // Medir o tempo de execu��o do insertion_sort
    clock_t start = clock();
    merge_sort(A, 0, n-1, aux);
    clock_t end = clock();

    printf("Array ordenado: \n");
    print_array(A, n);

    // Calcular o tempo de execu��o em segundos
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execu��o do insertion_sort: %f segundos\n", time_taken);

    // Liberar a mem�ria alocada
    free(A);

    return 0;
}
