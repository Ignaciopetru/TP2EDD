#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * Función que inicializa la stack con una cantidad entera de elementos
 * init_Stack: Int->Stack
 */
Stack init_Stack(int len) {
  return (Stack) {.data = malloc(sizeof(void *) * len),.pos = 0};
}

/**
 * Función que verifica si la stack está o no vacía
 * vacio_Stack: Stack->Bool
 */
int vacio_Stack(Stack stack) {
  return stack.pos == 0;
}

/**
 * Función que verifica si la stack posee solamente un elemento
 *largo_uno_solo: Stack->Bool
 */
int largo_uno_solo(Stack stack) {
  return stack.pos == 1;
}

/**
 * Función que permite agregar un elemento al stack
 * push_stack: Stack, void* -> Stack 
 */
Stack push_stack(Stack stack, void *elem) {
  stack.data[stack.pos] = elem;
  stack.pos++;
  return stack;
}

/**
 * Función que permite sacar un elemento de la stack
 * pop_stack: Stack -> Stack
 */
Stack pop_stack(Stack stack) {
  stack.pos--;
  return stack;
}

/**
 * Función que permite "Ojear" los datos del primer elemento de la stack
 * peek_Stack: Stack -> void*
 */
void *top_Stack(Stack stack) {
  if (stack.pos == 0)
    return NULL;
  else
    return stack.data[stack.pos - 1];
}

/**
 * Función que permite liberar la memoria del stack
 * destruir_Stack(Stack)
 */
void destruir_Stack(Stack stack) {
  free(stack.data);
}
