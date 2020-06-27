#include<stdio.h>
#include<stdlib.h>
#include "peca.h"
#include "imprimetab.h"
int main(int *argc, char *argv[]){
	int i;//primeira dimensão de vetores e int auxiliar
	int j;//segunda dimensão de vetores e int auxiliar
	peca *pecas;
	pecas=malloc(sizeof(peca)*108);//alocando espaço para peças
	peca **tabuleiro;//matriz de structs utilizada como tabuleiro
	tabuleiro=(peca**)malloc(sizeof(peca*)*6);//a matriz vai ter inicialmente 6x6 structs abertas
	for(i=0;i<6;i++){
		tabuleiro[i]=(peca*)malloc(sizeof(peca)*6);//aloca as colunas da matriz
		for (j=0;j<6;j++){
			tabuleiro[i][j].num=' ';//starta os parametro com espaço
			tabuleiro[i][j].letra=' ';//starta os parametros com espaço
		}
	}
	imprimetab(tabuleiro,6,6);//imprime o tabuleiro inicial
	j=0;
	while(j<108){//inicializando as peças
		i=0;
		while(i<6){
			pecas[j].num='1'+i;
			pecas[j++].letra='a'+i;
			i++;
		}
	}
}
