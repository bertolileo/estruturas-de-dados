#include "queue.h"

Queue* create () {
  return NULL;
}

void destroy (Queue *q) {
  while (q != NULL) {
    Queue *t = q->next;
    free(q);
    q = t;
  }
}

int empty (Queue *q) {
  return (q == NULL);
}

Queue* enqueue (Queue *q, int elem) {
  Queue *node = (Queue *)malloc(sizeof(Queue));
  node->data = elem;
  node->next = NULL;
  Queue *t = q;
  if (q == NULL) {
    return node;
  } else {
    while (t->next != NULL)
        t = t->next;
    t->next = node;
    return q;
  }
}

Queue* dequeue (Queue *q) {
  if (!empty(q)){
    Queue *t = q->next;
    free(q);
    q = t;
  }
  return q;
}

int get_front (Queue *q) {
  return q->data;
}

void print (Queue *q) {
  Queue *t;
  printf ("List: ");
  for (t = q; t != NULL; t = t->next)
    printf ("%d ", t->data);
  printf("\n");
}

