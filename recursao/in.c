#include "list.h"
#include <limits.h>

/* */
int in (List *l, int k) {
  if(l == NULL){
    return 0;
  } else {
    return (l->data == k ? 1 : in(l->next, k));
  }
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 0; k <= 5; k++) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  int num = 51, num2 = 203;
  printf("In = %d\n", in(l,num));
  printf("In = %d\n", in(l,num2));
  destroy (l);
  return 0;
}
