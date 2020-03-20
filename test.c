#include <stdio.h>
#include <stdlib.h>

int insere_um_valor (int *p, int valor){
	int x;
		for (x=0; x<10; x++){
			if (p[x]== -1) {
				p[x]=valor
			}
			else {
				printf("ESTRUTURA CHEIA")
			}
		}
}

int inicia_vet(int *ptvet){
	int x;
		for (x=0; x<10; x++){
			ptvet[x]= -1;
		}
}

int main (){
	int vet[10], x, *vetp;
		*vetp= vet[10];
		inicia_vet(*vetp);
	
	
	return 0;
}

