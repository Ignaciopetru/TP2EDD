#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

typedef struct _AVLNodo *AVLTree;

typedef struct _Intervalo {
    double inicio;
    double final;
}Intervalo;

AVLTree itree_crear();

void itree_destruir(AVLTree);

AVLTree itree_insertar(AVLTree, Intervalo *);

AVLTree itree_intersecar(AVLTree, Intervalo *);

AVLTree itree_eliminar(AVLTree, Intervalo *, int);

void itree_recorrer_dfs(AVLTree);

void itree_recorrer_bfs(AVLTree);

#endif