#include "queue.h"
#include <time.h>

void jackpot (int n, int r) {
  int correto, aux, ganhou = 1;
  Queue *q = create(n + 1);
  for(int i = 0; i < r; i++) {
    correto = rand() % 10;
    enqueue(q, (rand() % 10));
    for (int j = 1; j < n; j++) {
        aux = rand() % 10;
        if (aux != correto)
            ganhou = 0;
        enqueue(q, aux);
    }
    if (ganhou) {
        print(q);
        printf(" -> Ganhou!!aaaaaaaaaaaaa");
        break;
    } else {
        print(q);
        while (!empty(q)){
            dequeue(q);
        }
    }
  }
  destroy(q);
}

int main () {
  srand(time(NULL));
  int n = 3;  /*número de carretéis*/
  int r = 10000; /*sequência de números em cada carretel*/
  jackpot (n, r);
}
