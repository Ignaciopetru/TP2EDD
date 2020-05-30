#ifndef ESTRUCTURA_DE_DATOS_I_2020_TP1_STACK_H
#define ESTRUCTURA_DE_DATOS_I_2020_TP1_STACK_H

typedef struct {
  void **data;
  int pos;
} Stack;

/**
 * Función que inicializa la stack con una cantidad entera de elementos
 * init_Stack: Int->Stack
 */
Stack init_Stack(int len);

/**
 * Función que verifica si la stack está o no vacía
 * vacio_Stack: Stack->Bool
 */

int vacio_Stack(Stack stack);

/**
 * Función que verifica si la stack posee solamente un elemento
 *largo_uno_solo: Stack->Bool
 */
int largo_uno_solo(Stack stack);

/**
 * Función que permite agregar un elemento al stack
 * push_stack: Stack, void* -> Stack 
 */
Stack push_stack(Stack stack, void *elem);

/**
 * Función que permite sacar un elemento de la stack
 * pop_stack: Stack -> Stack
 */
Stack pop_stack(Stack stack);

/**
 * Función que permite "Ojear" los datos del primer elemento de la stack
 * peek_Stack: Stack -> void*
 */
void *top_Stack(Stack stack);

/**
 * Función que permite liberar la memoria del stack
 * destruir_Stack(Stack)
 */
void destruir_Stack(Stack stack);

#endif                          //ESTRUCTURA_DE_DATOS_I_2020_TP1_STACK_H
