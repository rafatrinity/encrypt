#include "arvore.h"
#include <bits/stdc++.h>
using namespace std;

/* Estrutura de Dados 
 * Aluno: Rafael Trindade
 * Professor: Ricardo Mesquita
 * Veja mais em: https://github.com/rafatrinity
 * Universidade: UniCarioca
 */

//estrutura do nó
struct NO{
	struct NO* dir;
	struct NO* esq;
	char info;
};

//cria arvore
struct NO** cira_arvore(){
	struct NO** raiz = (struct NO**) new struct NO*;
	if(raiz != NULL)
		*raiz=NULL;
	return raiz;
}
//libera cada nó filho ao nó passado
void libera_NO(struct NO* no){
	libera_NO(no->esq);
	libera_NO(no->dir);
	free(no);
	no=NULL;
}
// libera tudo e destroi arvore
void libera_arvore(NO** raiz){
	if(raiz==NULL)
		return;
	libera_NO(*raiz);
	free(raiz);
}
// verifica se a arvore está vazia
int esta_vazia(NO** raiz){
	if(raiz==NULL||*raiz==NULL)
		return 1;
	return 0;
}
//verifica a altura da arvore
int altura_arvore(NO** raiz){
	if(raiz==NULL||*raiz==NULL)
		return 0;
	int alt_esq = altura_arvore(&((*raiz)->esq));
	int alt_dir = altura_arvore(&((*raiz)->dir));
	if(alt_dir>alt_esq)
		return (alt_dir+1);
	return (alt_esq+1);
}
//conta os nós
int qt_no(NO** raiz){
	if(raiz==NULL||*raiz==NULL)
		return 0;
	int qt_esq = qt_no(&((*raiz)->esq));
	int qt_dir = qt_no(&((*raiz)->dir));
	return (qt_esq+qt_dir+1);
}
//percorredo arvore e mostrando dados.
//em ordem, pre ordem e pos ordem
void pre_ordem(NO** raiz){
	if(raiz==NULL||*raiz==NULL)
		return;
	cout<<(*raiz)->info;
	pre_ordem(&((*raiz)->esq));
	pre_ordem(&((*raiz)->dir));
}
void em_ordem(NO** raiz){
	if(raiz==NULL||*raiz==NULL)
		return;
	em_ordem(&((*raiz)->esq));
	cout<<(*raiz)->info;
	em_ordem(&((*raiz)->dir));
}
void pos_ordem(NO** raiz){
	if(raiz==NULL||*raiz==NULL)
		return;
	pos_ordem(&((*raiz)->esq));
	pos_ordem(&((*raiz)->dir));
	cout<<(*raiz)->info;
}
//insere um elemento na arvore
int inserir(NO** raiz, int valor){
	if(raiz==NULL)
		return 0;
	struct NO* novo = new struct NO;
	if(novo==NULL)
		return 0;
	novo -> info = valor;
	novo -> esq = NULL;
	novo -> dir = NULL;
	if(*raiz==NULL)
		*raiz=novo;
	else{
		struct NO* atual=*raiz;
		struct NO* ant=NULL;
		while(atual!=NULL){
			ant=atual;
			if(atual->info==valor){
				free(novo);
				return 0;
			}
			if(valor > atual->info)
				atual = atual -> dir;
			else
				atual = atual -> esq;
		}
		if(valor > ant -> info)
			ant -> dir=novo;
		else
			ant -> esq=novo;
	}
	return 1;
}
//função auxiliar à função remover
struct NO* remove_atual(NO* atual){
	struct NO *no1, *no2;
	if(atual->esq==NULL){
		no2 = atual->dir;
		free(atual);
		return no2;
	}
	no1=atual;
	no2=atual->esq;
	while(no2->dir != NULL){
		no1=no2;
		no2=no2->dir;
	}
	if(no1!=atual){
		no1->dir=no2->esq;
		no2->esq=atual->esq;
	}
	no2->dir=atual->dir;
	free(atual);
	return no2;
}
//remove um elemento na arvore
int remover(NO** raiz, int valor){
	if(raiz==NULL)
		return 0;
	struct NO* ant=NULL;
	struct NO* atual = *raiz;
	while(atual != NULL){
		if(atual->info==valor){
			if(atual==*raiz)
				*raiz=remove_atual(atual);
			else{
				if(ant->dir==atual)
					ant->dir=remove_atual(atual);
				else
					ant->esq=remove_atual(atual);
			}
			return 1;
		}
	}
	ant=atual;
	if(valor > atual->info)
		atual = atual->dir;
	else
		atual = atual->esq;
}

//busca um elemento na arvore
int consultar(NO** raiz, int valor){
	if (raiz == NULL)
		return 0;
	struct NO* atual = *raiz;
	while(atual != NULL){
		if(valor==atual->info)
			return 1;
		if(valor > atual->info)
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return 0;
}