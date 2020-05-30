#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "dlist.h"

struct _Queue{
  DList primero;
  DList ultimo;
};

Queue queue_new () {
    Queue cola = malloc(sizeof(struct _Queue));
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

int queue_isEmpty (Queue cola) {
  return cola->primero == NULL;
}

void queue_agregar (Queue cola, void *dato) {
  if (queue_isEmpty(cola)) {
    cola->primero = dnodo_agregar_inicio(cola->primero, dato);
    cola->ultimo = cola->primero;
  } else
    cola->primero = dnodo_agregar_inicio(cola->primero, dato);
}

void* queue_sacar (Queue cola) {
  if (cola->primero == NULL)
    return NULL; 
  void * dato = dnodo_dato(cola->ultimo);
  DList ultimo = cola->ultimo;
  cola->ultimo = dnodo_ant(cola->ultimo);
  free(ultimo);
  return dato;
}

void queue_destruir (Queue cola) {
  dlist_destruir(cola->primero, NULL);
  free(cola);
}