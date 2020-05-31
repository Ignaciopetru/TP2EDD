#include <stdio.h>
#include <stdlib.h>
#include "headers/stack.h"

Stack stack_new(int largo) {
  Stack stack;
  stack.array = malloc(sizeof(void *) * largo);
  stack.pos = 0;
  return stack;
}

int stack_isEmpty(Stack stack) {
  return stack.pos == 0;
}

Stack stack_push(Stack stack, void *elem) {
  stack.array[stack.pos] = elem;
  stack.pos++;
  return stack;
}

Stack stack_pop(Stack stack) {
  stack.pos--;
  return stack;
}

void *stack_top(Stack stack) {
  if (stack.pos == 0)
    return NULL;
  else
    return stack.array[stack.pos - 1];
}

void stack_destruir(Stack stack) {
  free(stack.array);
}