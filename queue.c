#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"

// Estructura de almacenamiento.
struct _Queue {
    void **array;
    int primero, ultimo, numElem;
    int MAX_ELEM;
};

Queue queue_new(int largo) {
    // Reserva de memoria para la estructura y la array que contiene la informacion.
    Queue queue = malloc(sizeof(struct _Queue));
    queue->array= malloc(sizeof(void *)*largo);
    // Inicializacion de variables.
    queue->MAX_ELEM = largo ;
    queue->numElem = 0;
    queue->primero = 0;
    queue->ultimo = -1;
    return queue;
}

int queue_isEmpty(Queue queue) {
    return queue->numElem == 0;
}

Queue queue_agregar(Queue queue, void *elem) {
    if (queue->numElem == queue->MAX_ELEM) {
        queue->MAX_ELEM++;
        queue->array = realloc(queue->array,sizeof(int) * queue->MAX_ELEM);
    }
    else {
        queue->ultimo = (queue->ultimo+1) % queue->MAX_ELEM;
        queue->array[queue->ultimo] = elem;
        queue->numElem++;
    }
    return queue;
}
void *queue_sacar(Queue queue) {
    if (!queue_isEmpty(queue)) {
        void *elem = queue->array[queue->primero];
        queue->primero = (queue->primero + 1) % queue->MAX_ELEM;
        queue->numElem--;
        return elem;
    }
    else {
        return NULL;
    }
}

void queue_destruir(Queue queue) {
    free(queue->array);
    free(queue);
}