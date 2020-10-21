#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int vetorPrincipal[TAM];

void dobrar(int *x){
    *x = *x * 2;
}

void ordenar(int vetorAux[], int posicao){
	int resposta, v;
  int i, j, reserva;
  v=posicao;
  resposta= ehPosicaoValida(v);
  if (resposta==-1){
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
}
/*
Objetivo: criar estrutura auxiliar na posi��o 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - j� tem estrutura na posi��o
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espa�o de mem�ria
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){

	int retorno=0;
	int resposta, v;
  v=posicao;
  resposta= ehPosicaoValida(v);
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
Objetivo: inserir n�mero 'valor' em estrutura auxiliar da posi��o 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - n�o tem espa�o
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){
	int retorno=0;
	int resposta, v;
  v=posicao;
  resposta= ehPosicaoValida(v);
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
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Ap�s excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta � uma exclus�o l�gica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
	int retorno=0;
	int resposta, v;
  v=posicao;
  resposta= ehPosicaoValida(v);
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
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posi��o 'posicao'.
Caso seja excluido, os n�meros posteriores devem ser movidos para as posi��es anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta � uma exclus�o l�gica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posi��o 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    NUMERO_INEXISTENTE - N�mero n�o existe
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
	int x, y, retorno=0;
	int resposta, v;
  v=posicao;
  resposta= ehPosicaoValida(v);
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

// se posi��o � um valor v�lido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os n�meros da estrutura auxiliar da posi��o 'posicao (1..10)'.
os n�meros devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int x, retorno=0;
	int resposta, v;
  	v=posicao;
  	resposta= ehPosicaoValida(v);
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
Objetivo: retorna os n�meros ordenados da estrutura auxiliar da posi��o 'posicao (1..10)'.
os n�meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

	int x, retorno=0;
	int resposta, v;
  v=posicao;
  resposta= ehPosicaoValida(v);
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
Objetivo: retorna os n�meros de todas as estruturas auxiliares.
os n�meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int x, y, retorno=0, d=0;
	for(x=0; x<TAM; x++){
		if(pvet[x].aux!=NULL){
			for (y=0; y<pvet[x].qtdelementos ;y++){
				vetorAux[d]=pvet[x].aux[y];
				d++;
				retorno= SUCESSO;
			}	
		}
		else{
			retorno=SEM_ESTRUTURA_AUXILIAR;
		}	
	}
	return retorno;
	
}

/* Objetivo: retorna os n�meros ordenados de todas as estruturas auxiliares.
os n�meros devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar

*/

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int x, y, retorno=0, soma=0;
	
	
	
	return retorno;
}


/*
Objetivo: modificar o tamanho da estrutura auxiliar da posi��o 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - Posi��o inv�lida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho n�o pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na aloca��o do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
	int retorno=0, tamanhonew;
	int resposta, v;
  v=posicao;
  resposta= ehPosicaoValida(v);
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
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posi��o 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posi��o inv�lida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um n�mero int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
	int retorno=0;
	int resposta, v;
  v=posicao;
  resposta= ehPosicaoValida(v);
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
para poder liberar todos os espa�os de mem�ria das estruturas auxiliares.

*/

void finalizar(){
	int x=0;
    for(x=0;x<10;x++){
      free(pvet[x].aux);
    }
}

int main (){
	int x, vet[x], soma, y;
	FILE *abrir;
	inicializar();
	
	criarEstruturaAuxiliar(5,2);
	criarEstruturaAuxiliar(3,1);
	criarEstruturaAuxiliar(2,8);
	inserirNumeroEmEstrutura(15, 1);
	inserirNumeroEmEstrutura(20, 1);
	inserirNumeroEmEstrutura(25, 1);
	inserirNumeroEmEstrutura(3, 2);
	inserirNumeroEmEstrutura(1, 2);
	inserirNumeroEmEstrutura(2, 2);
	inserirNumeroEmEstrutura(4, 2);
	inserirNumeroEmEstrutura(4, 2);
	inserirNumeroEmEstrutura(250, 8);
	inserirNumeroEmEstrutura(252, 8);
	getDadosDeTodasEstruturasAuxiliares(vet);
	
	for(x=0;x<TAM;x++){
		soma=soma+pvet[x].qtdelementos;
	}
	
	printf("%d", soma);
	
	abrir=fopen("t3.txt", "w");
	if(abrir==NULL){
		printf("Erro ao abrir o arquivo");
	}
	else{
		int d;
		for(d=0; d<10; d++){
			fprintf(abrir,"%d \n",vet[d]);
		}
		fclose(abrir);
	}	

	return 0;
}

