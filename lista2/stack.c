#include "stack.h"

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
  while (s != NULL) {
    Stack *t = s->next;
    free(s);
    s = t;
  }
}

Stack* push (Stack *s, int elem) {
  Stack *node = (Stack*) malloc (sizeof(Stack));
  node->data = elem;
  node->next = s;
  return node;
}

Stack* pop (Stack *s) {
  if (!empty(s)){
    Stack *t = s->next;
    free(s);
    s = t;
  }
  return s;
}

int get_peek (Stack *s) {
  return s->data;
}

int empty (Stack *s) {
  return (s == NULL);
}

void print (Stack *s) {
  Stack *t;
  printf ("List: ");
  for (t = s; t != NULL; t = t->next)
    printf ("%d ", t->data);
  printf("\n");
}
