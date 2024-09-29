#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  if (c[0] == ')' || c[0] == ']'){
    free(s);
    return 0;
  }

  while (c[i] != '\0') {
    if (c[i] == '[' || c[i] == '(') {
        push(s, c[i]);
    }else if (c[i] == ']') {
        if (pop(s) != '[') {
            free(s);
            return 0;
        }
    }else if (c[i] == ')') {
        if (pop(s) != '(') {
            free(s);
            return 0;
        }
    }
    i++;
  }

  if (!empty(s))
    free(s);
    return 0;
  return 1;
  free(s);
}

int main () {
  char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c))
    printf("true  (bem formada)\n");
  else
    printf("false (mal formada)\n");
  return 0;
}
