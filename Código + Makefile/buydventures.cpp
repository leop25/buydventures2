#include "buydventures.h"
#include <iostream>

void CriaLista(Lista *L) {
    L->Ultimo = -1;
}
void InsereUltimoLista(Lista *L, Item I) {
    L->Ultimo++;
    L->Itens[L->Ultimo] = I;
}
bool Pesquisa(Lista *L, Chave C) {
    Posicao i;
    for (i=0; i <= L->Ultimo; i++) {
        if(L->Itens[i].chave == C) {
            return true;
        }
    }
    return false;
}
void RemoveElemento(Lista *L, Posicao P) {

    Posicao i;

    if (!(P <= L->Ultimo)) {
        return;
    }

    for (i = P; i < L->Ultimo; i++) {
        L->Itens[i] = L->Itens[i+1];
    }

    L->Ultimo--;

}
void RemoveElementoPorChave(Lista *L, Chave C) {
    RemoveElemento(L, Pesquisa(L, C));
}
bool VerificaListaCheia(Lista *L) {
    return L->Ultimo == MAXTAM - 1;
}
bool VerificaListaVazia(Lista *L) {
    return L->Ultimo == -1;
}

void GeraCasas(Tabuleiro *T){
    T->lobo[0] = rand()%25;
    T->lobo[1] = rand()%25;
    T->lobo[2] = rand()%25;
    T->lobo[3] = rand()%25;
    T->lobo[4] = rand()%25;
}
bool isLobo(Tabuleiro *T){
    return T->casa == T->lobo[0] || T->casa == T->lobo[1] || T->casa == T->lobo[2] || T->casa == T->lobo[3] || T->casa == T->lobo[4];
}
void GeraCompra(Tabuleiro *T, Chave *C){
    T->lista[0] = C[0];
    T->lista[1] = C[1];
    T->lista[2] = C[2];
    T->lista[3] = C[3];
    T->lista[4] = C[4];
}