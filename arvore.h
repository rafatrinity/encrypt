#ifndef arvore
#define arvore
#include "arvore.cc"

/* Estrutura de Dados 
 * Aluno: Rafael Trindade
 * Professor: Ricardo Mesquita
 * Veja mais em: https://github.com/rafatrinity
 * Universidade: UniCarioca
 */

typedef class NO* ArvBin;
int esta_vazia(ArvBin* raiz);
int altura_arvore(ArvBin* raiz);
int qt_no(ArvBin* raiz);
int inserir(ArvBin* raiz, int valor);
int remover(ArvBin* raiz, int valor);
int consultar(ArvBin* raiz, int valor);
void pre_ordem(ArvBin* raiz);
void em_ordem(ArvBin* raiz);
void pos_ordem(ArvBin* raiz);
void libera_arvore(ArvBin* raiz);
#endif