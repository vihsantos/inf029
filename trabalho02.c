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
	int *aux, qtdelementos, ttaux;	
}bloco;

bloco pvet[TAM];


typedef struct reg {
	int conteudo;
  struct reg *prox;
} No;

No *inicio=NULL;

void inicializar(){
	int x;
	
	for(x=0;x<10;x++){
		pvet[x].aux=NULL;
		pvet[x].ttaux=0;
		pvet[x].qtdelementos=0;
	}
}

void finalizar(){
	int x=0;
	for(x=0;x<10;x++){
		free(pvet[x].aux);
	}
}

int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;
}

void ordenar(int vetorAux[], int posicao){
	int i, j, reserva;
	for(i=0;i<pvet[posicao].qtdelementos;i++){
		for(j=i+1;j<pvet[posicao].qtdelementos; j++){
			if(vetorAux[i]>vetorAux[j]){
				reserva=vetorAux[i];
				vetorAux[i]=vetorAux[j];
				vetorAux[j]=reserva;
			}
		}
	}
}

int criarEstruturaAuxiliar(int posicao, int tamanho){
	int retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if (resposta==-1){
		posicao--;
		if (tamanho>=1){
			if(pvet[posicao].aux==NULL){
				pvet[posicao].aux=(int *)malloc(tamanho * sizeof(int));
				pvet[posicao].ttaux=tamanho;
				retorno= SUCESSO;
			}
			else{
				retorno=JA_TEM_ESTRUTURA_AUXILIAR;
			}	
		}
		else{
			retorno= TAMANHO_INVALIDO;
		}	
	}
	else{
		retorno=POSICAO_INVALIDA;
	}
	
	return retorno;
}

int inserirNumeroEmEstrutura(int valor, int posicao){
	int retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;	
		if(pvet[posicao].aux!=NULL){
			if(pvet[posicao].qtdelementos<=pvet[posicao].ttaux){
				pvet[posicao].aux[pvet[posicao].qtdelementos]=valor;
				pvet[posicao].qtdelementos++;
				retorno=SUCESSO;
			}
			else{
				retorno=SEM_ESPACO;
			}
		}
		else{
			retorno=SEM_ESTRUTURA_AUXILIAR;
		}
	}
	else{
		retorno= POSICAO_INVALIDA;
	}
	return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao){
	int retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;		
		if(pvet[posicao].aux!=NULL){
			if(pvet[posicao].qtdelementos!=0){
				pvet[posicao].aux[pvet[posicao].qtdelementos]=pvet[posicao].aux[pvet[posicao].qtdelementos+1];
				pvet[posicao].qtdelementos--;
				retorno=SUCESSO;
			}
			else{
				retorno=ESTRUTURA_AUXILIAR_VAZIA;
			}
	
		}
		else{
			retorno=SEM_ESTRUTURA_AUXILIAR;
		}
	}
	else{
		retorno= POSICAO_INVALIDA;
	}
	
	return retorno;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){	
	int x, y, retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;
		if(pvet[posicao].aux!=NULL){
			if(pvet[posicao].qtdelementos!=0){
				for(x=0; x<pvet[posicao].qtdelementos; x++){
					if(pvet[posicao].aux[x]==valor){
						for(y=x; y<pvet[posicao].qtdelementos-1; y++){
							pvet[posicao].aux[y]=pvet[posicao].aux[y+1];
						}
						retorno=SUCESSO;
						pvet[posicao].qtdelementos--;
					}
					else{
						retorno=NUMERO_INEXISTENTE;
					}
				}
			}
			else{
				retorno=ESTRUTURA_AUXILIAR_VAZIA;
			}
		}
		else{
				retorno=SEM_ESTRUTURA_AUXILIAR;
		}
	}
	else{
		retorno= POSICAO_INVALIDA;
	}
	return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int x, retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;
		if(pvet[posicao].aux!=NULL){
			for (x=0; x<pvet[posicao].qtdelementos;x++){
				vetorAux[x]=pvet[posicao].aux[x];
				retorno= SUCESSO;
			}
		}
		else{
			retorno=SEM_ESTRUTURA_AUXILIAR;
		}
	}
	else{
		retorno=POSICAO_INVALIDA;
	}	

	return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int x, retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;
		if(pvet[posicao].aux!=NULL){
			for (x=0; x<pvet[posicao].qtdelementos ;x++){
				vetorAux[x]=pvet[posicao].aux[x];
				retorno= SUCESSO;
			}
			ordenar(vetorAux, posicao);
		}
		else{
			retorno=SEM_ESTRUTURA_AUXILIAR;
		}
	}
	else{
		retorno=POSICAO_INVALIDA;
	}	

	return retorno;
	}


int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
	int retorno=0, tamanhonew;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;
		tamanhonew= novoTamanho + pvet[posicao].ttaux;
		if (tamanhonew>=1){
			if(pvet[posicao].aux==NULL){
				retorno=SEM_ESTRUTURA_AUXILIAR;
			}
			else{
				pvet[posicao].aux=(int *)malloc(tamanhonew * sizeof(int));
				pvet[posicao].ttaux=tamanhonew;
				retorno= SUCESSO;
			}	
		}
		else{
			retorno= TAMANHO_INVALIDO;
		}		
	}
	else{
		retorno=POSICAO_INVALIDA;
	}

	return retorno;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){
	int retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;
		if(pvet[posicao].aux!=NULL){
			if(pvet[posicao].qtdelementos>0){
				return pvet[posicao].qtdelementos;
			}
			else{
				retorno=ESTRUTURA_AUXILIAR_VAZIA;
			}
		}
	}
	else{
		retorno=POSICAO_INVALIDA;		
	}
	return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int x, y, retorno=0, resultado;
	
	for(x=0; x<TAM; x++){
		if(pvet[x].aux!=NULL){
			for(y=0; y<pvet[x].qtdelementos;y++){
				vetorAux[y]=pvet[x].aux[y];
				retorno= SUCESSO;
			}
		}
		else{
			retorno=SEM_ESTRUTURA_AUXILIAR;
		}
	}
	return retorno;
}

No* montarListaEncadeadaComCabecote(){
	int valor, x, y;
	No *v;
	
	v=(No*) malloc(sizeof(No));
	
	if(v==NULL){
		return NULL;
	}
	
	for(x=0; x<10; x++){
		valor=getQuantidadeElementosEstruturaAuxiliar(x);
		if(valor=0){
			return NULL;
		}
		else {
			for (y=0;y<=valor; y++){
				v->conteudo = pvet[x].aux[y];
   				v->prox = NULL;
   				
   				if (inicio==NULL){
   					inicio = v;
				}	
   				else {
	  				v->prox = inicio;
	  				inicio  = v;
					}
			}
		}
	}
}

void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
	No *v;
	int cont=0;

	v = inicio;
	while (v !=NULL) {
	    vetorAux[cont]=v->conteudo;
	    v = v->prox;
	    cont++;
	}	
}
void destruirListaEncadeadaComCabecote(No** inicio){
	No *v;
    v = (*inicio)->prox;
    free(*inicio);
    (*inicio) = v;
}

int main (){
	int x, resultado, rere, vet[4], lala, a, b, ex, set, ex2, nav[4];
	
	inicializar();
	resultado=criarEstruturaAuxiliar(2, 10);
	rere=inserirNumeroEmEstrutura(9,2);
	b=inserirNumeroEmEstrutura(2,2);
	lala= inserirNumeroEmEstrutura(6,2);
	a=inserirNumeroEmEstrutura(8,2);
	
	
	ex=getDadosOrdenadosEstruturaAuxiliar(2, vet);
	
	
	for(x=0;x<4;x++){
		printf("---- %d", vet[x]);
	}

/*	resultado=criarEstruturaAuxiliar(2, 10);
	printf("\nO resultado eh : %d", resultado);
	
	rere=inserirNumeroEmEstrutura(2, 5);
	b=inserirNumeroEmEstrutura(2, 8);
	printf("\nO resultado eh : %d", rere);
	a=getDadosEstruturaAuxiliar(2, vet);
	int x;
	for(x=0;x<2;x++){
		printf("\n %d", vet[x]);
	}
	
	printf("%d", a);
*/

/*
	lala=inserirNumeroEmEstrutura(2, 6);
	a=inserirNumeroEmEstrutura(2, 7);
	b=inserirNumeroEmEstrutura(2, 8);
	
	printf(" %d ", pvet[2].aux[0]);
	printf("%d ", pvet[2].aux[1]);
	printf("%d ", pvet[2].aux[2]);
	printf("%d ", pvet[2].aux[3]);
*/
	return 0;
}
