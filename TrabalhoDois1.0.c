#include <stdio.h>
#include <stdlib.h>

struct estrutura_principal{
	int vet[10];
	int *vetprin;
	int pos;
};

struct estrutura_auxiliar {
	int *conteudo;
	int casinhas;
	int contador;
	struct estrutura_auxiliar *novo;
};

int inserir_elemento_prin(int p, int *vet, int valor){
	if (p<10){
		vet[p]=valor;
		return 0;
	}
	else
	{
		return 1;
	}
	
}

void inserir_elemento_aux (int pos, int *conteud, int tam, int *vetor){
	int x;
	vetor[pos]= *conteud;
	conteud= NULL;
	
	conteud=(int *) malloc(tam*sizeof(int));
		for (x=0; x<=tam; x++){
			printf("Insira um numero: ");
			scanf("%d", &conteud[x]);
		}
}

int main (){
	
	
	
	return 0;
}
