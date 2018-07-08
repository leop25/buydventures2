#include <iostream>
#include <cstring>
#include <time.h>
#include <clocale>
#include "buydventures.h"

using namespace std;

Chave listaItems[5] = {"Bolinho de chocolate", "Barra de Chocolate Branco", "Chá", "Maçãs", "Açúcar"}; //Lista de itens a serem oferecidos na loja

int main() {
    setlocale(LC_ALL, ""); //Permite o uso de caracteres de outros alfabetos
    srand(time(NULL));

    Lista L;
    Item item;
    Posicao P;

    //Variáveis de operações
    char opt;
    int opt2;
    int cont = 0;

    //Características do jogo
    Tabuleiro player;

    //---------- INÍCIO DO JOGO ---------//
    CriaLista(&L);
    GeraCasas(&player);

    cout << "█ Vamos começar? (S)im ou (S)im?" << endl << "██╠ ";
    cin >> opt;

    if(toupper(opt) == 'S') {
        GeraCompra(&player, listaItems);
        while(player.casa < 20) {
            //Andar
            cout << "█ Andar (1) ou (2) casas?" << endl << "██╠ ";
            cin >> opt;
            while (opt != '1' && opt != '2') {
                cout << "█ Input inválido, escreva novamente..." << endl << "██╠ ";
                cin >> opt;
            }
            if (opt == '1') {
                player.casa += 1;
            } else {
                player.casa += 2;
            }
            //Comprar
            int value = rand()%5;
            cout << "█ Casa " << player.casa << ") " <<  "Você deseja comprar o item \"" << listaItems[value] << "\" por [10] de OURO? (S)im ou (N)ão?" << endl << "██╠ ";
            cin >> opt;
            while (toupper(opt) != 'S' && toupper(opt) != 'N') {
                cout << "█ Input inválido, escreva novamente..." << endl << "██╠ ";
                cin >> opt;
            }
            if(toupper(opt) == 'S'){
                if(player.gold < 10){
                    cout << "█ Desculpe, mas você não tem ouro suficiente pra isso..." << endl << endl;
                }else if(VerificaListaCheia(&L)){
                    cout << "█ Desculpe, mas você não tem espaço no seu inventário..." << endl << endl;
                }else{
                    player.gold -= 10;
                    item.chave = listaItems[value];
                    InsereUltimoLista(&L, item);
                    cout << "█ Obrigado pela sua aquisição" << endl;
                    cout << "█ Agora você tem [" << player.gold << "] de OURO" << endl << "█████████████████████████████▓▓▓▓▒▒▒░" << endl;
                }
            }

            //Lobo
            if(isLobo(&player)){
                player.luck = rand()%3 + 1;
                cout << "███ LOBO: Grrrrr... É bom você me dar o que você tem aí... Senão..." << endl;
                cout << "█ Quanta comida você vai dar? (1 a 3) "<< endl << "██╠ ";
                cin >> opt2;
                while(cont <= player.luck){
                    for(int i = 0; i < opt2; i++){
                        RemoveElemento(&L,L.Ultimo);
                        cont++;
                    }
                }
                if(opt2 == player.luck){
                    cout << "███ LOBO: Bom mesmo... Até a próxima HAHAHAHAHA!" << endl;
                }else if(opt2 > player.luck){
                    cout << "███ LOBO: Tudo isso? Não precisava... Mentira! Precisava sim! Até a próxima HAHAHAHAHA!" << endl;
                }
            }

            //Fim
            if(player.casa >= 20) {
                cont = 0;
                for (int i = 0; i < 5; i++) {
                    if (Pesquisa(&L, listaItems[i])) {
                        cout << "██ Você tem " << listaItems[i] << endl;
                        for(int x = 0; x < 5; x++){
                            if(listaItems[i] == player.lista[x]){
                                cont++;
                            }
                        }
                    }
                }
                cout << "██████████ Você conseguiu " << cont << " itens da lista! ███████████" << endl;
            }
        }
    }


	return 0;
}
