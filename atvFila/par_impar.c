#include "queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main () {
  int i = 0, n = 4, num;
  Queue *par = create(n);
  Queue *impar = create(n);
  srand(time(NULL));

  while (i < n) {
    num = rand() % 10;
    if (num % 2 == 0)
        enqueue(par, num);
    else
        enqueue(impar, num);

    i++;
  }
  print(par);
  print(impar);
  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/
  return 0;
}

