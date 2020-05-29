#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "dlist.h"

struct _Queue{
  DList primero;
  DList ultimo;
};

Queue queue_new () {
    Queue cola;
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

void queue_agregar(Queue cola, void *dato) {
    if(cola->primero = NULL)
        
}