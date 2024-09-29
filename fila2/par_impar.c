#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
  srand(time(NULL));
  int i, n = 10;
  Queue *q = create(n+1);
  Queue *impar = create(n+1);
  Queue *par = create(n+1);
  for (i = 0; i < n; i++){
    enqueue(q, rand() % 21);
  }
  print(q);
  for (i = 0; i < n; i++){
    int elem = dequeue(q);
    if (elem % 2 == 0){
        enqueue(par, elem);
    } else {
        enqueue(impar, elem);
    }
  }
  printf("PARES ---> ");
  print(par);
  printf("IMPARES ---> ");
  print(impar);

  destroy(par);
  destroy(q);
  destroy(impar);
  return 0;
}

