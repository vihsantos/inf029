#include <stdio.h>
#include <stdlib.h>
#define TAM 5


void inicializavet (int vet[]){
	int x;
		vet[0]=8;
		vet[1]=9;
		vet[2]=2;
		vet[3]=1;
		vet[4]=5;
}
void imprimevet(int vet[]){
	int x;
	for(x=0; x<TAM; x++){
		printf("%d ",vet[x]);
	}	
}
void excluinum(int vet [], int valor){
	int x, y, ultimo;
	ultimo=TAM;
	for(x=0; x<ultimo; x++){
		if (vet[x]==valor){
			for(y=x; y<ultimo-1; y++){
				vet[y]=vet[y+1];
			}
				ultimo--;
		}
	}
}
void excluiultimo(int vet[], int ultimo){
	if (vet[ultimo]!=0){
		vet[ultimo]=0;
	}
	else {
		ultimo--;
		excluiultimo(vet, ultimo);
	}
}

int main (){
	
	int vetor[TAM], excluir, resultado;

	inicializavet(vetor);
	//imprimevet(vetor);
	
/*	printf("\nInforme o valor que deseja excluir: ");
	scanf("%d", &excluir);
	excluinum(vetor, excluir);
*/
	
//	excluiultimo(vetor,TAM);
	
	//imprimevet(vetor);
	
	
	return 0;
}
