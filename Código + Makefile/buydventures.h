#ifndef BUYDVENTURES_H

#include <iostream>
#include <cstring>

using namespace std;

#define MAXTAM 5

typedef string Chave;
typedef int Posicao;

typedef struct {
    Chave chave;
} Item;

typedef struct {
    Item Itens[MAXTAM];
    Posicao Ultimo;
} Lista;

typedef struct{
    int gold = 100; //Total de gold inicial do player
    int casa = 0; //Posição atual do jogador
    int luck; //Indice que será utilizado para os momentos de "sorte" do player
    int lobo[5]; //Lista de posições do lobo
    string lista[5]; //Lista de compras
}Tabuleiro;

//Funções de Lista
void CriaLista(Lista *L);
void InsereUltimoLista(Lista *L, Item I);
bool Pesquisa(Lista *L, Chave C);
void RemoveElemento(Lista *L, Posicao P);
void RemoveElementoPorChave(Lista *L, Chave C);
bool VerificaListaCheia(Lista *L);
bool VerificaListaVazia(Lista *L);

//Funções de Mecânica
void GeraCasas(Tabuleiro *T); //Define a posição das casas especiais (No caso, do lobo)
bool isLobo(Tabuleiro *T); //Função para identificar se a casa é de um lobo
void GeraCompra(Tabuleiro *T, Chave *C); //Função para gerar a lista de compras

#endif