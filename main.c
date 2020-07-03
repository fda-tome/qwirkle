#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "entrada.h"
#include "tab.h"

int main(int *argc, char *argv[]) {
	int i; //primeira dimensão de vetores e int auxiliar
	int j; //segunda dimensão de vetores e int auxiliar
	jogador *jogadores;
	int nJog;
	peca *pecas;
	
	pecas = (peca *) malloc (sizeof(peca) * 108); //alocando espaço para peças
	
	inicializaPecas(pecas); //inicializa as peças do jogo
	system("clear || cls");
	printf("Bem-vindo ao Qwirkle! =)\n\nInsira o numero de jogadores (2 a 18): ");
	setbuf(stdin, NULL);
	scanf("%d", &nJog);
	while(nJog > 18 || nJog < 2) {
		printf("Oh oh! Numero de jogadores invalido. Por favor, tente novamente inserindo numeros de 2 a 18.");
		setbuf(stdin, NULL);
		scanf("%d", &nJog);
	}

	jogadores = (jogador *) malloc(sizeof(jogador) * nJog); //alocação dos jogadores
	configuraJogo (nJog, jogadores, pecas); //inicializa os jogadores com seus nomes, suas peças e suas pontuações (0)
	peca **tabuleiro; //matriz de structs utilizada como tabuleiro
	tabuleiro = (peca **) malloc(sizeof(peca *) * 6);//a matriz vai ter inicialmente 6x6 structs abertas
	
	for(i=0; i<6; i++) {
		tabuleiro[i] = (peca *) malloc(sizeof(peca) * 6); //aloca as colunas da matriz
		for (j=0; j<6; j++) {
			//inicializa as posições do tabuleiro com espaços
			tabuleiro[i][j].num=' ';
			tabuleiro[i][j].letra=' ';
		}
	}	
	
	for(i = 0; i < nJog; i++) {
		printf("Jogador %d: %s", i+1, jogadores[i].nome);
		printf("Peças: ");
		for(j = 0; j < 6; j++) {
			printf("%c%c ", jogadores[i].pecasJog[j].letra, jogadores[i].pecasJog[j].num);
		}
		printf("\n");
	}
}
