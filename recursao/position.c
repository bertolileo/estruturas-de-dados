#include "list.h"
#include <limits.h>
/* */
int position (List *l, int k) {
  if (l != NULL){
    if (l->data == k){
        return 0;
    }else {
        int res = position(l->next, k);
        if (res == -1)
            return -1;
        return 1 + res;
    }
  }
  return -1;
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Position of %d = %d\n", 9, position(l, 9));
  printf("Position of %d = %d\n", 4, position(l, 4));
  printf("Position of %d = %d\n", 2, position(l, 2));
  printf("Position of %d = %d\n", 22, position(l, 22));
  printf("Position of %d = %d\n", 18, position(l, 10));
  destroy (l);
  return 0;
}
