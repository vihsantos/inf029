#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct {
	int valor[TAM];
}lista;

lista li[TAM];

int main (){
	int x, y;
	li[0].valor[0]=2;
	li[0].valor[1]=4;
	li[0].valor[2]=6;
	li[1].valor[0]=1;
	li[1].valor[1]=3;
	li[1].valor[2]=9;
	li[2].valor[0]=10;
	li[2].valor[1]=12;
	li[2].valor[2]=14;
	
	for(x=0;x<TAM;x++){
		for(y=0;y<TAM;y++){
			printf("%d \n", li[x].valor[y]);
		}
	}
}
