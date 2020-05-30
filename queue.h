#ifndef QUEUE_H_INLCUDED
#define QUEUE_H_INLCUDED

typedef struct _Queue QueueA;

typedef QueueA* Queue;

Queue queue_new ();

int queue_isEmpty (Queue);

void queue_agregar (Queue, void*);

void * queue_sacar (Queue);

void queue_destruir (Queue);

#endif
