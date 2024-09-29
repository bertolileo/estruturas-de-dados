#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main () {
  srand(time(NULL));
  int i, n = 10;
  Queue *q = create(n);
  for (i = 0; i < n; i++){
    enqueue(q, rand() % 21);
  }
  print(q);
  return 0;
}

