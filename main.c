#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"
#include "lists/queue.h"
#include "lists/stack.h"
#define MAX_ERROR 200


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


Intervalo* entrada_validar (char *codigo) {
  
  char *funcion = malloc(sizeof(char)*MAX_ERROR);
  char *errorNuCor = malloc(sizeof(char)*MAX_ERROR);
  char *errorFinal = malloc(sizeof(char)*MAX_ERROR);
  double inicio = 0, final = 0;
  int argCorrectos = sscanf(codigo, "%s [ %lf , %lf %[^]]]", funcion, &inicio, &final, errorNuCor);
  
  sscanf(strstr(codigo, "]"), "] %[^\r\n]\n", errorFinal);

  if (argCorrectos == 3 && strcmp(errorNuCor, "") == 0 && strcmp(errorFinal, "") == 0 && (strcmp(funcion, "i ") ||strcmp(funcion, "e ")||strcmp(funcion, "? "))) {
    if (inicio <= final) {
      Intervalo * intervalo = malloc(sizeof(Intervalo));
      intervalo->inicio = inicio;
      intervalo->final = final;
      free(funcion);
      free(errorNuCor);
      return intervalo;
    }
    else
      printf("El intervalo es invalido\n");
  } else {
    printf("El comando esta mal escrito\n");
    free(funcion);
    free(errorNuCor);
    return NULL;
  }
}


int main() {

  AVLTree arbol = itree_crear();
  printf("Interface v0.01\n");
  int salida = 0;
  while (!salida) {
    char * codigo = malloc(sizeof(1024));
    codigo = fgets(codigo, 1024, stdin);
    int largo = strlen(codigo);
    codigo = realloc(codigo, sizeof(char)*largo);

    char primerLetra = codigo[0];
  
    switch (primerLetra){
      case 'd':
        if (strcmp(codigo, "dfs\n") == 0)
          itree_recorrer_dfs(arbol, (Visitante) intervalo_imprimir);
        else
          printf("Quiso escribir dfs? Intente nuevamente.\n");
        break;
      case 'b':
        if (strcmp(codigo, "bfs\n") == 0)
          itree_recorrer_bfs(arbol, (Visitante) intervalo_imprimir);
        else
          printf("Quiso escribir bfs? Intente nuevamente.\n");
        break;
      case 's':
        if (strcmp(codigo, "salir\n") == 0){
          salida = 1;
          printf("Saliendo del programa.\n");
        }
        else
          printf("Quiso escribir salir? Intente nuevamente.\n");
        break;
      case 'i':{
        Intervalo * intervalo = entrada_validar(codigo);
        if (intervalo == NULL)
          break;
        arbol = itree_insertar(arbol, intervalo);
        printf("Nodo: ");
        intervalo_imprimir(intervalo);
        printf("Insertado\n");
        break;
      }
      case 'e':{
        Intervalo * intervalo = malloc(sizeof(Intervalo));
        sscanf(codigo, "%*s [%lf, %lf]", &(intervalo->inicio), &(intervalo->final));
        itree_eliminar(arbol, intervalo, 0);
        break;
      }
      case '?':{
        Intervalo * intervalo = malloc(sizeof(Intervalo));
        sscanf(codigo, "%*s [%lf, %lf]", &(intervalo->inicio), &(intervalo->final));
        AVLTree nodo = itree_intersecar(arbol, intervalo);
        printf("[%lf, %lf]", nodo->intervalo->inicio, nodo->intervalo->final);
        break;
      }
      default:
        printf("Comando invalido, intente nuevamente");
        break;
    }
    free(codigo);
  }
  itree_destruir(arbol);






/*
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
*/
  
}

