#include "list.h"

/* */
List* insert_back (List *l, int k) {
  if (l == NULL) {
    l = (Node*)malloc(sizeof(Node));
    l->data = k;
    l->next = NULL;
  }
  else {
    l->next = insert_back (l->next, k);
  }
  return l;
}

/* */
List* removek (List *l, int k) {
  List *t;
  for (t = l; t != NULL; t = t->next){
    if (t->next->data == k){
        t->next = t->next->next;
        free(t->next);
        break;
    }
  }
  return l;
}

/* */
void print (List* l) {
  if (l != NULL) {
    printf("%d ", l->data);
    print (l->next);
  }
}

/* */
void destroy (List *l) {
  while (l != NULL) {
    List *t = l->next;
    free(l);
    l = t;
  }
}

