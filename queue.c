#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"

struct _Queue {
    void **queue;
    int primero, ultimo, numElem;
    int MAX_ELEM;
};

Queue queue_new(int cant) {
    Queue q = malloc(sizeof(struct _Queue));
    q->queue= malloc(sizeof(void *)*cant);
    q->MAX_ELEM=cant ;
    q->numElem=0;
    q->primero=0;
    q->ultimo=-1;
    return q;
}
int queue_isEmpty(Queue q)
{
    return(q->numElem==0);
}
Queue queue_agregar(Queue q, void * d)
{
    if(q->numElem == q->MAX_ELEM){
        q->MAX_ELEM++;
        q->queue=realloc(q->queue,sizeof(int)*q->MAX_ELEM);
    }
    else{
        q->ultimo=(q->ultimo+1)%q->MAX_ELEM;
        q->queue[q->ultimo]=d;
        q->numElem++;
    }
    return q;
}
void *queue_sacar(Queue q)
{
    if(!queue_isEmpty(q))
    {
        void *d=(q->queue[q->primero]);
        q->primero=((q->primero)+1)%(q->MAX_ELEM);
        (q->numElem)--;
        return d;
    }
    else
    {
        return NULL;
    }
}