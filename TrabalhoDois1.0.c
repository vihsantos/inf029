#include <stdio.h>
#include <stdlib.h>

struct estrutura_principal{
	int vet[10];
	int *vetprin;
	int limite;
	int pos;
};

struct estrutura_auxiliar {
	int conteudo;
	int tamanho;
	int pos;
	struct estrutura_auxiliar *novo;
};

int inserir_elemento_prin(int p, int *vet, int valor){
	if (pos<10){
		vet[pos]=valor;
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int inserir_elemento_aux (){
	
}

int main (){
	
	
	
	return 0;
}
