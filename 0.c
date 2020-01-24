#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valida_data(char data[]);

int main (){

	char data[13];		
	
	strcpy(data, "10/06/2000");
	
	int retorno= valida_data(data);
				
	return 0;
}

int valida_data(char data[]){
	
	char sDia[3], sMes[3], sAno[5];
	int iDia, iMes, iAno;
	int i, j, k;
	

	for(i=0; data[i]!= '/'; i++){
		sDia[i]= data[i];	
	}
		printf("%s\n", sDia);
	
	int vetMes=0;
	for(j=i; data[j]!= '/'; j++, vetMes++){
		sMes[vetMes]= data[j];	
	}
		printf("%s\n", sMes);
	
	
}

int eh_numero(char c){
	
}
