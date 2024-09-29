#include "queue.h"
#include <time.h>

void shuffle (Queue *q){
    int num = rand() % 100;
    for (int i = 0; i < num; i++){
        enqueue(q, dequeue(q));
    }
}

void jackpot (int n, int r) {
    Queue *q1 = create(r), *q2 = create(r), *q3 = create(r);
    for (int i = 1; i < r; i++) {
        enqueue(q1, i);
        enqueue(q2, i);
        enqueue(q3, i);
    }
    int win = 0, jogadas = 0;
    while (!win){
        shuffle(q1);
        shuffle(q2);
        shuffle(q3);
        printf("%d %d %d", front(q1), front(q2), front(q3));

        if (front(q1) == front(q2) && front(q1) == front(q3) && front(q2) == front(q3)){
            win = 1;
            printf(" -> Ganhou");
            printf("\nNUMERO DE JOGADAS: %d", jogadas);
        }
        printf("\n");
        jogadas++;
    }
}

int main () {
  srand(time(NULL));
  int n = 3;  /*número de carretéis*/
  int r = 10; /*sequência de números em cada carretel*/
  jackpot (n, r);
}
