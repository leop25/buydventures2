Feito por: Leonardo Penna de Lima
RA - 726559

SOBRE O JOGO:

• O usuário começa com 100 moedas de ouro e é perguntado a cada turno se ele deseja andar 1 ou 2 casas. Se cair em uma casa normal, ele é perguntado se deseja comprar um item posicionado aleatoriamente, pelo custo de 10 de ouro. Se ele tiver as moedas necessárias e seu inventário não estiver cheio, ele consegue adquirir o produto.

• O objetivo do jogo é comprar todos os itens

• O inventário do jogador é uma LISTA

• O LOBO come seus itens através do sistema de remoção do último item seu inventário, logo, ele come os itens que você oferece, sendo que ele tem um número mínimo de itens que devem ser comidos, sendo assim, o usuário pode dar mais ou menos itens que o necessário

• Existem 5 LOBOS espalhados pelo tabuleiro.


MODULARIZAÇÃO DO CÓDIGO:

main.cpp:
• Dividido em: 
	• Mecânica de andar casa a casa 
	• Mecânica de compras
	• Funcionamento do Lobo
	• Avaliação do final do jogo

buydventures.h:
• Dividido em:
	• Declaração de funções da estrutura de Lista
	• Declaração de funções da mecânica do jogo
	• Declaração de estruturas de funcionamento do jogo

buydventures.cpp:
• Dividido em:
	• Funcionamento das funções da estrutura de lista
	• Funcionamento da mecânica do jogo


COMO COMPILAR:
• Compilação direta: g++ -o BuyDventures main.cpp buydventures.cpp
 -> Rodar o executável gerado  
• Makefile: make -f makefile.dms
 -> Rodar o executável gerado



 

 