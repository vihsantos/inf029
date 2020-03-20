#include <stdio.h>
#include <stdlib.h>

 int insere_valor (int *p){
	int x, cod, valor;
		for (x=0; x<10; x++){
			if (p[x]==-1) {
				printf("DIGITE 1 SE DESEJA ADCIONAR SOMENTE UM ELEMENTO NO VETOR.\n");
				printf("DIGITE 2 SE DESEJA ADCIONAR UMA CADEIA DE ELEMENTOS NO VETOR.\n");
				scanf("%d", &cod);
				
				switch(cod){
					case 1: {
						printf("INSIRA O VALOR \n");
						scanf("%d", &valor);
							p[x]= valor;
						break;
					}
					case 2: {
						
						break;
					}
					default {
						
						break;
					}
				}
				
			}
		}
	
}


int main (){
	int vet[10], x, *vetp;
	
	for (x=0; x<10; x++){
		vet[x]= -1;
	}
		*vetp= vet[10];
	
	
	return 0;
}

