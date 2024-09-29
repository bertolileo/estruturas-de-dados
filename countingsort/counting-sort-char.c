#include "utils.h"
#include <ctype.h>
void counting_sort(FILE *f, int range) {
    int i;
    int C[range + 1];
    int total = 0;
    for (i = 0; i <= range; i++) {
        C[i] = 0;
    }
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            C[ch - 'a']++;
            total++;
        }
    }
    printf("Letra\tContagem\tFrequência\n");
    for (i = 0; i <= range; i++) {
        if (C[i] > 0) {
            printf("%c\t%d\t\t%.4f\n", 'a' + i, C[i], (double) C[i] / total);
        }
    }
}

/* Função principal */
int main(int argc, char *argv[]) {
    /*if (argc < 2) {
        printf("run: %s file.txt\n", argv[0]);
        exit(1);
    }*/

    // Abrir o arquivo para leitura
    // FILE *f = fopen(argv[1], "r");
    FILE *f = fopen("livro_pt.txt", "r");

    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int range = 25; // Número de letras do alfabeto (a-z)

    counting_sort(f, range);

    fclose(f);

    return 0;
}
