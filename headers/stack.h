#ifndef STACK_H
#define STACK_H

// Estructura Stack.
typedef struct {
  void **array;
  int pos;
} Stack;

// stack_new inicializa la stack con la cantidad de espacio determinada.
Stack stack_new(int);

// stack_isEmpty retorna 1 si la stack esta vacia, 0 si no lo esta.
int stack_isEmpty(Stack);

// stack_push agraga un elemento a la stack, en el "tope" de la misma.
Stack stack_push(Stack, void *);

// stack_pop elimina el elemento del "tope" de la stack.
Stack stack_pop(Stack);

// stack_top retorna el elemento del "tope" de la stack.
void *stack_top(Stack);

// stack_destruir libera la memoria utilizada por la stack.
void stack_destruir(Stack);

#endif                 

