#include <stdio.h>
#include <stdlib.h>

typedef struct _Intervalo {
    double inicio;
    double final;
} Intervalo;

typedef struct _AVLNodo {
    Intervalo dato;
    int altura;
    double mayorFinal;
    struct _AVLNodo *der;
    struct _AVLNodo *izq;
} AVLNodo;

typedef AVLNodo *AVLTree;

// Funciones auxiliares

int obtener_altura(AVLTree arbol) {
    if (arbol)
        return arbol->altura;
    return 0;
}

int obtener_balance(AVLTree arbol){
    return obtener_altura(arbol->der) - obtener_altura(arbol->izq);
}

// Funciones creacion
AVLTree itree_crear() {
    return NULL;
}


// Funciones comparacion
AVLTree itree_intersectar(){}

// Funciones destrucción
AVLTree itree_eliminar(AVLTree arbol, Intervalo dato){
  if(arbol == NULL)
    return arbol;
  if(dato.inicio < arbol->dato.inicio)
    arbol->izq = itree_eliminar(arbol->izq, dato); //! Cada recursion se copia "Intervalo dato"
  else if(dato.inicio > arbol->dato.inicio)
    arbol->der = itree_eliminar(arbol->der, dato); //TODO El recorrido izq / der se puede hacer aparte
  else{
    if(arbol->der == NULL || arbol->izq == NULL){
      AVLTree temp = arbol->izq ? arbol->izq : arbol->der;
      // Sin hijos
      if(temp == NULL){
        temp = arbol;
        arbol = NULL;
      } else // Caso un hijo
        *arbol = *temp;
      free(temp);
    } else {
      // Caso dos hijos
//??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
      // Busco el nodo menor del hijo derecho
      AVLNodo* actual = arbol->der;
      while(actual->izq != NULL)
        actual = actual->izq;
      
      // Copio los datos del nodo encontrado y borro ese nodo
      arbol->dato = actual->dato;
      arbol->der = itree_eliminar(arbol->der, actual->dato);
//???????????????????????????????????????????????????????????????????????????????????????????
    }
  }
  // Si no quedan nodos tras la eliminacion, retornamos
  if(arbol == NULL)
    return arbol;

  // Actualizo la altura si es necesaria
  arbol->altura = 1 + max(obtener_altura(arbol->der), obtener_altura(arbol->izq));

  // Calculo el balance del nodo
  int balance = obtener_balance(arbol);

  // Retorno el arbol tras balancearlo
  return balancear(arbol, balance);
}
AVLTree itree_destruir(){}

// Funciones recorrer
AVLTree itree_recorrer_dfs(){}
AVLTree itree_recorrer_bfs(){}


int main() {
    
}