#include "stack.h"

int main () {
  int tam = 6, elem;
  Stack *s = create (tam);
  srand(time(NULL));
  int i;
  for (i = 0; i < tam; i++) {
    push (s, rand()%10);
  }
  print (s);
  Stack *aux = create(get_size(s));
  while (!empty(s)) {
    elem = pop(s);
    if(elem % 2 != 0) {
        push(aux, elem);
    }
  }
  print(aux);
  while (!empty(aux)) {
    push(s, pop(aux));
  }
  print (s);
  /*TERMINAR*/
  destroy (s);
}
