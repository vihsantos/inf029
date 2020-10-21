#include <stdio.h>
#include <stdlib.h>


int main (){
	
	FILE *abrir;
	int b;
	
	abrir= fopen("t3.txt", "w");
	
	
	if(abrir==NULL){
		printf("Erro ao abrir o arquivo");
	}
	else{
		int x;
		for(x=0; x<10; x++){
			printf("Insira um valor: ");
			scanf("%d", &b);
			fprintf(abrir,"%d \n",b);
		}
		fclose(abrir);
	}
	
	
	return 0;
}
