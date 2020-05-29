#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct _Stack{
  void** array;
  int primero;
  int largo;
};

Stack stack_new (int largo) {
  Stack stack = malloc(sizeof(Stack));
  stack->array = malloc(sizeof(void*)*largo);
  stack->largo = largo;
  stack->primero = -1;
  return stack;
}

int stack_isEmpty (Stack stack) {
  return stack->primero == -1;
}

int stack_unoSolo (Stack stack) {
  return stack->primero == 0;
}


void stack_push (Stack stack, void* dato) {
  if (stack->primero + 1 == stack->largo) {
    printf("Se esta exediendo la capacidad de la stack");
    return;
  }
  stack->array[stack->primero + 1] = dato;
  stack->primero ++;
}


void* stack_top (Stack stack) {
  return stack->array[stack->primero];
}

void stack_pop (Stack stack) {
  stack->array[stack->primero] = NULL;
  stack->primero --;
}


void stack_destruir (Stack stack) {
  free(stack->array);
  free(stack);
}
