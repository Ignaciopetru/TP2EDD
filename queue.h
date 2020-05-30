#ifndef QUEUE_H_INLCUDED
#define QUEUE_H_INLCUDED

typedef struct _Queue* Queue;

Queue queue_new ();

void queue_agregar (Queue, void*);

void queue_sacar (Queue);

int queue_isEmpty (Queue);

void queue_destruir (Queue);

#endif
