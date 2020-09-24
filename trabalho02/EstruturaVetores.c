#include <stdio.h>
#include <stdlib.h>
#define TAM 10


#include "EstruturaVetores.h"

int vetorPrincipal[TAM];

void dobrar(int *x){

    *x = *x * 2;


}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){

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

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
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

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
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

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
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

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int x, retorno=0;
	int resposta= ehPosicaoValida(posicao);
	if(resposta==-1){
		posicao--;
		if(pvet[posicao].aux!=NULL){
			for (x=0; x<pvet[posicao].qtdelementos ;x++){
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


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
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

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int x, y, retorno=0, resultado;
	
	for(x=0; x<TAM; x++){
		if(pvet[x].aux!=NULL){
			for(y=0; y<pvet[x].qtdelementos;y++){
				vetorAux[y]=pvet[x].aux[y];
				retorno= SUCESSO;
			}
				for (x=0; x<TAM; x++){
					ordenar(vetorAux, x);
				}
		}
		else{
			retorno=SEM_ESTRUTURA_AUXILIAR;
		}
	}
	return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
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

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
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

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
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

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote(){

    return NULL;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){


}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
   

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar(){
    int x;
	
	for(x=0;x<10;x++){
		pvet[x].aux=NULL;
		pvet[x].ttaux=0;
		pvet[x].qtdelementos=0;
	}
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
	int x=0;
	for(x=0;x<10;x++){
		free(pvet[x].aux);
	}
}

