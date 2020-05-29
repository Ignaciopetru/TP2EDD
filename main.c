#include <stdio.h>
#include <stdlib.h>

typedef struct _Intervalo {
    double inicio;
    double final;
} Intervalo;

typedef struct _AVLnodo {
    Intervalo dato;
    int altura;
    double mayorFianl;
    struct _AVLnodo *rigth;
    struct _AVLnodo *left;
} AVLnodo;

typedef AVLnodo *AVLtree;

int obtenerAltura(AVLnodo *nodo) {
    if (nodo)
        return nodo->altura;
    return 0;
}

AVLtree itree_crear() {
    return NULL;
}



int main() {
    
}