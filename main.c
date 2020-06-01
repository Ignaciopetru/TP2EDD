#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"
#include "lists/queue.h"
#include "lists/stack.h"


//TODO

//-itree crear ✔️
  // * Implementar ✔️

//-itree destruir✔️
  // * Implementar ✔️
  // * Checkear que no haya filtraciones de memoria ✔️

//-itree insertar✔️
  // * Analizar que pasa con el segundo valor (ver en itree_destruir) ✔️

//-itree eliminar✔️
  // * Falta liberar la memoria del nodo y el puntero de su padre que apunta a el ✔️

// itree intersetar✔️
  // * Implementar ✔️
  // * Testear su funcionamiento ✔️

// itree recorrer dfs ✔️
  // * Checkear que no haya filtraciones de memoria ✔️

// itree recorrer bfs ✔️
  // * Checkear que no haya filtraciones de memoria ✔️

// mayorFinal (AVLNodo) ✔️
  // * Usarla para la busqueda ✔️
  // * Usarlo para no revisar el arbol si el mayorTotal es menor al inicial del dato ✔️

// Interfaz
  // * Hacerla (main)
  // * Crear intervalo

// Queue y Stack ✔️
  // * Ver tema crecimiento dinamico ✔️
  // * Mejorar escritura✔️

// inodo_liberar✔️
  // * Implementar ✔️
  // * Ver si no filtramos memoria ✔️
  
// AVL
  // * Pasar a su propio archivo y cabecera

// Rotar ✔️
  // * Testear derecha izquierda e izquierda derecha ✔️

// Informe
  // * Hacer

// * Ver si no filtramos memoria en los que tiene la tag ✔️



int main() {

  printf("Interface v0.01");
  char * codigo = malloc(sizeof(1024));
  codigo = fgets(codigo, 1024, stdin);
  int largo = strlen(codigo);
  codigo = realloc(codigo, sizeof(char)*largo);
  printf("%s", codigo);
  char primerLetra = codigo[0];

  switch (primerLetra){
    case 'd':
      printf("DFS");
      break;
    case 'b':
      printf("BFS");
      break;
    case 's':
      printf("SALIR");
      break;
    case 'i':
      int i;
      for (i = 0; codigo[i]; i++) {

      }
      break;
    
    default:
      break;
  }







  //AVLTree arbol = NULL;
  AVLTree arbol = NULL;
  // Creacion
  
  for(double i=1; i < 30; i=i+2){
    Intervalo* aux = (Intervalo*)malloc(sizeof(Intervalo));
    aux->inicio = i;
    if (i == 13){
      aux->final = 400;
    }else{
      aux->final = i+1;
    }
    arbol = itree_insertar(arbol, aux);
  }

  Intervalo *a = malloc(sizeof(Intervalo));
  a->inicio = 17;
  a->final = 19;
  itree_insertar(arbol, a);


  // Eliminacion
  //inorder(arbol);

  itree_recorrer_bfs(arbol);
  puts("");
  //itree_recorrer_dfs(arbol);
  itree_destruir(arbol);

  
}

