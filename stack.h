#ifndef STACK_H_INLCUDED
#define STACK_H_INLCUDED

typedef struct _Stack* Stack;

Stack stack_new (int);

void stack_push (Stack, void*);

void stack_pop (Stack);

void* stack_top (Stack);

int stack_unoSolo (Stack);

int stack_isEmpty (Stack);

void stack_destruir (Stack);

#endif
