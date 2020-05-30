#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "dlist.h"

typedef struct _Queue{
  DList primero;
  DList ultimo;
};

Queue queue_new () {
    Queue cola;
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

int queue_isEmpty (Queue cola) {
  return cola->primero == NULL;
}

void queue_agregar(Queue cola, void *dato) {
  if (cola->primero = NULL) {
    cola->primero = dnodo_agregar_inicio(NULL, dato);
    cola->ultimo = cola->primero;
  } else
    cola->primero = dnodo_agregar_inicio(cola->primero, dato);
}

void* queue_sacar (Queue cola) {
  if (cola->primero == NULL)
    return NULL; 
  void * dato = cola->ultimo->dato;
  DList ultimo = cola->ultimo;
  cola->ultimo = cola->ultimo->ant;
  free(ultimo);
  return dato;
}

void queue_destruir (Queue cola) {
  dlist_destruir(cola->primero, NULL);
  free(cola);
}

