#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"
#include "lists/queue.h"
#include "lists/stack.h"
#define MAX_ERROR 200


// Informe
  // * Hacer


int intervalo_verificar(char *inicio, char *final, Intervalo *intervalo) {
  char *errorI;
  double inicioD = strtod(inicio, &errorI);
  char *errorF;
  double finalD = strtod(final, &errorF);
  
  if (strcmp(errorI, "") != 0 || strcmp(errorF, "") != 0)
    return 0;
  if (finalD < inicioD)
    return 0;
  intervalo->inicio = inicioD;
  intervalo->final = finalD;
  return 1;
}


// error 1 = no corresponde a una funcion
// error 2 = intervalo invalido
// error 3 = existe residuo
char funcion_verificar(char *ident, char *inicio, char *final, char *residuo, Intervalo *intervalo) {
  // Chequeamos si existe residuo luego del ultimo ]
  if (strcmp(residuo, "") != 0)
    return '3';
  // Si no hay residuo y el identificador corresponde a un funcion con intervalo:
  if ((ident[0] == 'i' || ident[0] == 'e' || ident[0] == '?') && strlen(ident) == 2 && ident[1] == ' ') {
    // Verificamos que el intervalo sea valido:
    if (intervalo_verificar(inicio, final, intervalo))
      // Si es valido retorneamos el identificador
      return ident[0];
      // Sino codigo de error.
    else
      return '2';
  } else {
    // Si el identificador no corresponde a funciones con intervalo, comprobamos las restantes
    if (strcmp(ident, "dfs") == 0  || strcmp(ident, "bfs") == 0  || strcmp(ident, "salir") == 0)
      return ident[0];
  }
  // No corresponde a ninguna funcion valida
  return '1';
}

void copiar_seccion(char *comando, char *parte, int i, int *cont, int *indexToken, char eow){
  if (comando[i] == eow){
    (*indexToken)++;
    (*cont) = -1;
  }
  else
    parte[(*cont)] = comando[i];
}

char entrada_validar (char *comando, Intervalo *intervalo) {
  int i = 0, cont = 0;
  int indexToken = 0;
  char eows[] = "[,]"; 
  char *ident = calloc(1, sizeof(char)*50);
  char *inicio = calloc(1, sizeof(char)*50);
  char *final = calloc(1, sizeof(char)*50);
  char *residuo = calloc(1, sizeof(char)*50);
  for(; comando[i] != '\n' && comando[i] != '\r' ; i++, cont++) {
    // Copiamos residuo
    if (indexToken == 3) 
      copiar_seccion(comando, residuo, i, &cont, &indexToken, '-');
    // Copiamos final
    if (indexToken == 2) 
      copiar_seccion(comando, final, i, &cont, &indexToken, eows[2]);
    // Copiamos inicio
    if (indexToken == 1) 
      copiar_seccion(comando, inicio, i, &cont, &indexToken, eows[1]);
    // Copiamos el identificador hasta encontrar la llave.
    if (indexToken == 0) 
      copiar_seccion(comando, ident, i, &cont, &indexToken, eows[0]);
  }
  char primeraLetra = funcion_verificar(ident, inicio, final, residuo, intervalo);
  free(ident);
  free(inicio);
  free(final);
  free(residuo);

  return primeraLetra;

}


int main() {

  int salida = 1;
  AVLTree arbol = itree_crear();
  printf("Sea BIENVENIDO\n");
  while (salida) {
    char *comando = malloc(sizeof(char) * 200);
    // leemos con \n incluido
    fgets(comando, 200, stdin);
    
    comando = realloc(comando, sizeof(char) * strlen(comando));
    
    Intervalo *intervalo = malloc(sizeof(Intervalo));
    char identificador = entrada_validar(comando, intervalo);
    
    free(comando);
    
    switch (identificador)
    {
    case 'i':
      arbol = itree_insertar(arbol, intervalo);
      break;

    case 'e':
      arbol = itree_eliminar(arbol, intervalo, 0);
      free(intervalo);
      break;

    case '?':{
      AVLTree inter = itree_intersecar(arbol, intervalo);
      if (inter == NULL)
        printf("NO\n");
      else{
        printf("SI: ");
        intervalo_imprimir(inter->intervalo);      
      }
      free(intervalo);
      break;
    }
    case 'd':
      itree_recorrer_dfs(arbol, intervalo_imprimir);
      free(intervalo);
      break;

    case 'b':
      itree_recorrer_bfs(arbol, intervalo_imprimir);
      free(intervalo);
      break;

    case 's':
      printf("Saliendo del progrema\n");
      free(intervalo);
      salida = 0;
      break;

    case '1':
      printf("ERROR-Funcion invalida!\n");
      free(intervalo);
      break;

    case '2':
      printf("ERROR-Intervalo invalido!\n");
      free(intervalo);
      break;

    case '3':
      printf("ERROR-Caracteres irreconocibles tras ']'!\n");
      free(intervalo);
      break;

    default:
      free(intervalo);
      break;
    }
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
  return 0;
}

