#ifndef QUEUE_H_INLCUDED
#define QUEUE_H_INLCUDED

typedef struct _Queue* Queue;

Queue queue_new (int);

int queue_isEmpty (Queue);

Queue queue_agregar (Queue, void*);

void * queue_sacar (Queue);

void queue_destruir (Queue);

#endif
