#ifndef QUEUE_H_INLCUDED
#define QUEUE_H_INLCUDED

// Tipo de la queue.
typedef struct _Queue* Queue;

// queue_new crea la queue con la capacidad indicaca.
Queue queue_new (int);

// queue_isEmpty retorna 1 si es vacia, 0 en caso contrario.
int queue_isEmpty (Queue);

// queue_agregar agrega un elemento al final de la queue.
Queue queue_agregar (Queue, void*);

// queue_sacar saca el primer elemento de la queue.
void *queue_sacar (Queue);

// queue_destruir libera la memoria utilizada.
void queue_destruir (Queue);

#endif
