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
    struct _AVLnodo *der;
    struct _AVLnodo *izq;
} AVLnodo;

typedef AVLnodo *AVLTree;

int obtenerAltura(AVLnodo *nodo) {
    if (nodo)
        return nodo->altura;
    return 0;
}

AVLTree itree_crear() {
    return NULL;
}


int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

AVLTree rotar_derecha(AVLTree arbol) {
    // Reservamos el izq del arbol
    AVLTree copArbolIzq = arbol->izq;
    // Realizamos la rotacion perse
    arbol->izq = copArbolIzq->der;
    copArbolIzq->der = arbol;
    // Recalculamos altura
    arbol->altura = max(obtenerAltura(arbol->izq), obtenerAltura(arbol->der)) + 1;
    copArbolIzq->altura = max(obtenerAltura(copArbolIzq->izq), obtenerAltura(copArbolIzq->der)) + 1;
    // Se retorna el nuevo primer nodo
    return copArbolIzq;
}

AVLTree rotar_izquierda(AVLTree arbol) {
    // Reservamos el der del arbol
    AVLTree copArbolDer = arbol->der;
    // Realizamos la rotacion perse
    arbol->der = copArbolDer->izq;
    copArbolDer->izq = arbol;
    // Recalculamos altura
    arbol->altura = max(obtenerAltura(arbol->izq), obtenerAltura(arbol->der)) + 1;
    copArbolDer->altura = max(obtenerAltura(copArbolDer->izq), obtenerAltura(copArbolDer->der)) + 1;
    // Se retorna el nuevo primer nodo
    return copArbolDer;
}

AVLTree balancear(AVLTree arbol, int balance){
    //Izquierda Izquierda
    if(balance < -1 && obtener_balance(arbol->izq >= 0))
        return rotar_derecha(arbol);
    // Izquierda derecha
    if(balance < -1 && obtener_balance(arbol->izq < 0)){
        arbol->izq = rotar_izquierda(arbol->izq);
        return rotar_derecha(arbol);
    }
    // Derecha derecha
    if(balance > 1 && obtener_balance(arbol->izq <= 0))
        return rotar_izquierda(arbol);
    // Derecha izquieda
    if(balance > 1 && obtener_balance(arbol->izq > 0)){
        arbol->der = rotar_derecha(arbol->der);
        return rotar_izquierda(arbol);
    }
    // Arbol balanceado
    return arbol;
}


AVLTree insertar(AVLTree arbol, Intervalo dato) {
    // Si llegamos a nodo vacio insertamos nuestro nodo nuevo
    if (arbol == NULL) {
        //return crear nodo
    }
    // Buscamos la posicion que debe ocupar el nuevo nodo
    // segun BST
    if (dato.inicio > arbol->dato->inicio)
        arbol->izq = insertar(arbol->izq, dato);    
    if else (dato->inicio < arbol->dato->inicio)
        arbol.der = insertar(arbol->der, dato);
    // Caso en el que el nodo ya este en el arbol
    else
        return arbol;
    // Recalculamos la altura de cada nuevo nodo
    arbol->altura = 1 + max(arbol->izq->altura, arbol->der->altura);
    // Calculamos el valor de balance de el nodo y procedemos a balancear correctamente
    int balance = obtener_balance(arbol);
    return balancear(arbol, balance);
}



int main() {
    
}