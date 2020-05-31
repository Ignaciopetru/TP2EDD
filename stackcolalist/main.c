#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"



typedef struct _Intervalo {
    double inicio;
    double final;
} Intervalo;

typedef struct _AVLNodo {
    Intervalo *dato;
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
  if(arbol)
    return obtener_altura(arbol->der) - obtener_altura(arbol->izq);
  return 0;
}

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

// Funciones de rotacion
AVLTree rotar_derecha(AVLTree arbol) {
    // Reservamos el izq del arbol
    AVLTree copArbolIzq = arbol->izq;
    // Realizamos la rotacion perse
    arbol->izq = copArbolIzq->der;
    copArbolIzq->der = arbol;
    // Recalculamos altura
    arbol->altura = max(obtener_altura(arbol->izq), obtener_altura(arbol->der)) + 1;
    copArbolIzq->altura = max(obtener_altura(copArbolIzq->izq), obtener_altura(copArbolIzq->der)) + 1;
    // Se retorna el nuevo primer nodoz
    printf("Roto derecha\n");
    return copArbolIzq;
}

AVLTree rotar_izquierda(AVLTree arbol) {
    // Reservamos el der del arbol
    AVLTree copArbolDer = arbol->der;
    // Realizamos la rotacion perse
    arbol->der = copArbolDer->izq;
    copArbolDer->izq = arbol;
    // Recalculamos altura
    arbol->altura = max(obtener_altura(arbol->izq), obtener_altura(arbol->der)) + 1;
    copArbolDer->altura = max(obtener_altura(copArbolDer->izq), obtener_altura(copArbolDer->der)) + 1;
    // Se retorna el nuevo primer nodo
    printf("Roto izquierda\n");
    return copArbolDer;
}

AVLTree balancear(AVLTree arbol, int balance){
    //Izquierda Izquierda
    if(balance < -1 && obtener_balance(arbol->izq) <= 0)
        return rotar_derecha(arbol);
    // Izquierda derecha
    if(balance < -1 && obtener_balance(arbol->izq) > 0){
        arbol->izq = rotar_izquierda(arbol->izq);
        return rotar_derecha(arbol);
    }
    // Derecha derecha
    if(balance > 1 && obtener_balance(arbol->der) >= 0)
        return rotar_izquierda(arbol);
    // Derecha izquieda
    if(balance > 1 && obtener_balance(arbol->der) < 0){
        arbol->der = rotar_derecha(arbol->der);
        return rotar_izquierda(arbol);
    }
    // Arbol balanceado
    return arbol;
}


// Funciones creacion

AVLTree itree_crear() {
    return NULL;
}

AVLTree inodo_crear(Intervalo *dato) {
    AVLTree nodo = malloc(sizeof(AVLNodo));
    nodo->der = NULL;
    nodo->izq = NULL;
    nodo->altura = 1;
    nodo->mayorFinal = 0;
    nodo->dato = dato;
    return nodo;
}

AVLTree itree_insertar(AVLTree arbol, Intervalo *dato) {
    // Si llegamos a nodo vacio insertamos nuestro nodo nuevo
    if (arbol == NULL) {
        return inodo_crear(dato);
    }
    // Buscamos la posicion que debe ocupar el nuevo nodo
    // segun BST
    if (dato->inicio > arbol->dato->inicio)
        arbol->der = itree_insertar(arbol->der, dato);
    else if (dato->inicio < arbol->dato->inicio)
        arbol->izq = itree_insertar(arbol->izq, dato);
    // Caso en el que el nodo ya este en el arbol
    else
        return arbol;
    // Recalculamos la altura de cada nuevo nodo
    arbol->altura = 1 + max(obtener_altura(arbol->izq), obtener_altura(arbol->der));
    // Calculamos el valor de balance de el nodo y procedemos a balancear correctamente
    int balance = obtener_balance(arbol);
    return balancear(arbol, balance);
}

// Funciones comparacion
AVLTree itree_intersectar(){}

// Funciones destrucción
void inodo_liberar(AVLTree arbol) {
  free(arbol->der);
  free(arbol->izq);
  free(arbol);
}

AVLTree itree_eliminar(AVLTree arbol, Intervalo *dato){
  if(arbol == NULL){
    printf("No existe el nodo a destruir\n");
    return arbol;
  }
  if(dato->inicio < arbol->dato->inicio)
    arbol->izq = itree_eliminar(arbol->izq, dato);
  else if(dato->inicio > arbol->dato->inicio)
    arbol->der = itree_eliminar(arbol->der, dato); //TODO El recorrido izq / der se puede hacer aparte
  else if(dato->final < arbol->dato->final)
    arbol->izq = itree_eliminar(arbol->izq, dato);
  else if(dato->final > arbol->dato->final)
    arbol->der = itree_eliminar(arbol->der, dato);
  else{
    if(arbol->der == NULL || arbol->izq == NULL){
      AVLTree temp = arbol->izq ? arbol->izq : arbol->der;
      // Sin hijos
      if(temp == NULL){
        temp = arbol;
        arbol = NULL;
        printf("Nodo eliminado. Caso sin hijos\n");
      } else { // Caso un hijo
        arbol->dato = temp->dato;
        arbol->izq = temp->izq;
        arbol->der = temp->der;
        printf("Nodo eliminado. Caso un hijo\n");
        // ! Ver que hacer con maximoFinal
      }
      inodo_liberar(temp);
    } else { // Caso dos hijos
      // Busco el nodo menor del hijo derecho
      AVLNodo* actual = arbol->der;
      while(actual->izq != NULL)
        actual = actual->izq;

      // Copio los datos del nodo encontrado y borro ese nodo
      arbol->dato = actual->dato;
      printf("Nodo reemplazado. Caso dos hijos. Recursion para eliminar el remplazo\n");
      arbol->der = itree_eliminar(arbol->der, actual->dato);
    }
  }
  // Si no quedan nodos tras la eliminacion (caso inicial no hijos), retornamos
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
void inorder(AVLTree arbol) {
  if(arbol == NULL)
    return;
  inorder(arbol->izq);
  printf("[%f, %f]-%d\n", arbol->dato->inicio, arbol->dato->final, arbol->altura);
  inorder(arbol->der);
}

void itree_recorrer_dfs(AVLTree arbol) {
  Stack stack = stack_new();
  stack_push(stack, arbol);
  while (!stack_isEmpty(stack)) {
    AVLTree nodo = stack_top(stack);
    stack_pop(stack);
    if (nodo != NULL) {
      printf("[%f, %f]\n", nodo->dato->inicio, nodo->dato->final);
      stack_push(stack, nodo->der);
      stack_push(stack, nodo->izq);
    }
  }
  stack_destruir(stack);
}

void itree_recorrer_bfs(AVLTree arbol) {
  Queue queue = queue_new();
  queue_agregar(queue, arbol);
  while (!queue_isEmpty(queue)) {
    AVLTree nodo = queue_sacar(queue);
    if (nodo != NULL) {
      printf("[%f, %f]\n", nodo->dato->inicio, nodo->dato->final);
      queue_agregar(queue, nodo->izq);
      queue_agregar(queue, nodo->der);
    }
  }
  queue_destruir(queue);
}



int main() {

  //AVLTree arbol = NULL;
  AVLTree arbol = NULL;
  // Creacion
  for(double i=1; i < 16; i++){
    Intervalo* aux = (Intervalo*)malloc(sizeof(Intervalo));
    aux->inicio = i;
    aux->final = i+1;
    arbol = itree_insertar(arbol, aux);
  }
  // Eliminacion
  Intervalo* aux = (Intervalo*)malloc(sizeof(Intervalo));
  aux->inicio = 1;
  aux->final = 2;
  itree_eliminar(arbol, aux);
  //inorder(arbol);

  Intervalo* aux2 = (Intervalo*)malloc(sizeof(Intervalo));
  aux2->inicio = 2;
  aux2->final = 3;
  itree_eliminar(arbol, aux2);
  //inorder(arbol);

  Intervalo* aux3 = (Intervalo*)malloc(sizeof(Intervalo));
  aux3->inicio = 14;
  aux3->final = 15;
  itree_eliminar(arbol, aux3);
  //inorder(arbol);

  Intervalo* aux4 = (Intervalo*)malloc(sizeof(Intervalo));
  aux4->inicio = 14;
  aux4->final = 15;
  itree_insertar(arbol, aux4);
  //inorder(arbol);

  inorder(arbol);
  itree_recorrer_bfs(arbol);
  puts("");
  itree_recorrer_dfs(arbol);

}

