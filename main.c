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


int max(int a, int n) {
    if(a > b)
        return a;
    return b;
}

AVLtree insertar(AVLtree arbol, Intervalo dato) {
    if (arbol == NULL) {
        //return crear nodo
    }
    if (dato.inicio > arbol->dato->inicio)
        arbol->izq = insertar(arbol->izq, dato);    
    if else (dato->inicio < arbol->dato->inicio)
        arbol.der = insertar(arbol->der, dato);
    else
        return arbol;

    arbol->altura = 1 + max(arbol->izq->altura, arbol->der->altura);
    
    int balance = obter_balance(arbol);
    return balancear(arbol, balance);
}



int main() {
    
}