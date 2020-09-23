#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11

typedef struct{
	int *aux, qtdelementos, pos;	
}bloco;

bloco pvet[TAM];

void inicializar(){
	int x;
	
	for(x=0;x<10;x++){
		pvet[x].aux=NULL;
		pvet[x].pos=0;
		pvet[x].qtdelementos=0;
	}
	
}

// "return=0"=ERRO / "return=1"=SUCESSO

int criarEstruturaAuxiliar(int posicao, int tamanho){
	int retorno=0;
	
	if(pvet[posicao].aux==NULL){
		pvet[posicao].aux=(int *)malloc(tamanho * sizeof(int));
		retorno= SUCESSO;
	}
	else{
		retorno=JA_TEM_ESTRUTURA_AUXILIAR;
	}
	
	return retorno;
}

int inserirNumeroEmEstrutura(int posicao, int valor, bloco pvet[TAM]){
	int retorno=0;
	if(pvet[posicao].aux!=NULL){
		pvet[posicao].aux[pvet[posicao].qtdelementos]=valor;
		pvet[posicao].qtdelementos++;
		retorno=SUCESSO;
	}
	else{
		retorno=SEM_ESPACO;
	}
	return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao){
	pvet[posicao].aux--;
	pvet[posicao].qtdelementos--;
}

int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){	
	int x, y;
	for (x=0; x<= pvet[posicao].qtdelementos; x++){
		if (pvet[posicao].aux[x]==valor){
			for (y=x; y<=pvet[posicao].qtdelementos-1; y++){
				pvet[posicao].aux[y]=pvet[posicao].aux[y+1];
			}
		}
	}
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int x;
	for (x=0; x<=pvet[posicao].qtdelementos ;x++){
		vetorAux[x]=pvet[posicao].aux[x];
	}	
}
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int x;
	for (x=0; x<=pvet[posicao].qtdelementos; x++){
		vetorAux[x]=pvet[posicao].aux[x];
	}
	
}

int main (){
	int resultado;
	
	inicializar();
	
	resultado=criarEstruturaAuxiliar(2, 10);
	printf("O resultado eh : %d", resultado);
	return 0;
}
