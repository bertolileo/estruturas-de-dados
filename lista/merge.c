#include "list.h"

List* merge (List *A, List *B){
  List *C = NULL;
  List *T;
  while ((A != NULL) && (B != NULL)) {
    if (A->data <= B->data) {
        if (C == NULL) {
            C = A;
            T = A;
        }else {
            T->next = A;
            T = T->next;
        }
        A = A->next;
    }else {
        if (C == NULL) {
            C = B;
            T = B;
        } else {
            T->next = B;
            T = T->next;
        }
        B = B->next;
    }
  }
  if (A != NULL) {
    if(C == NULL){
        C = A;
    }else {
        T->next = A;
    }
  }else {
    if(C == NULL){
        C = B;
    }else {
        T->next = B;
    }
  }
  return C;
}

/**/
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2)
    B = insert (B, k);
  printf("LISTA A:\n");
  print (A);
  printf("LISTA B:\n");
  print (B);
  List *C = merge (A, B);
  printf("LISTA C:\n");
  print (C);
  destroy (C);
  return 0;
}
