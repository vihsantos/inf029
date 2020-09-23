#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct{
	int *aux, qtdelementos, pos, tamtotal;	
}bloco;

void inicializar(bloco *pvet){
	int x;
	
	for(x=0;x<10;x++){
		pvet[x].aux=NULL;
		pvet[x].pos=0;
		pvet[x].qtdelementos=0;
		pvet[x].tamtotal=0;
	}
	
}

// "return=0"=ERRO / "return=1"=SUCESSO

int criarEstruturaAuxiliar(int posicao, bloco pvet[TAM]){
	
	if ((posicao<0)&&(posicao>10)){
		return 0;
	}
	else {
		if ((pvet[posicao].tamtotal<0)&&(pvet[posicao].tamtotal>20)){
			return 0;			
		}
		else {
			if(pvet[posicao].aux==NULL){
				pvet[posicao].aux=(int *)malloc(pvet[posicao].tamtotal * sizeof(int));
				return 1;
			}
			else{
				return 0;
			}
		}
	}
}

int inserirNumeroEmEstrutura(int posicao, bloco pvet[TAM], int valor){
	if(pvet[posicao].aux!=NULL){
		if(pvet[posicao].qtdelementos<= pvet[posicao].tamtotal){
			pvet[posicao].aux[pvet[posicao].qtdelementos]=valor;
			pvet[posicao].qtdelementos++;
			return 1;
		}
		else{
			return 0;
		}
	}
	else {
		return 0;
	}
}

int excluirNumeroDoFinaldaEstrutura(int posicao, bloco pvet[TAM]){
	pvet[posicao].aux--;
}

//int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){	
//}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[], bloco pvet[TAM]){
	int x;
	for (x=0; x<=pvet[posicao].qtdelementos ;x++){
		vetorAux[x]=pvet[posicao].aux[x];
	}	
}
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[], bloco pvet[TAM]){
	int x;
	for (x=0; x<=pvet[posicao].qtdelementos; x++){
		vetorAux[x]=pvet[posicao].aux[x];
	}
	
}

int main (){
	int tamanho, pos;
	bloco principal[TAM];
	
	
	
	return 0;
}
