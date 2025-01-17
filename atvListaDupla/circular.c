#include "list.h"

List* create_circular (List *l) {
    List *t = l;
    while (t->next != NULL)
        t = t->next;
    t->next = l;
    return l;
}

int main () {
  int i;
  int n = 4;
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = create_circular(l);
  print (l);
  destroy (l);
  return 0;
}
