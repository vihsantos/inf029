#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehnumero(char c);
int validador_de_data (char data[]);

int main (){
	
	char data[15];
	int retorno=0;
	strcpy(data, "10/06/2000");
	
	retorno=validador_de_data(data);
	
	return 0;
}

int validador_de_data (char data[]){
	char sDia[3], sMes[3], sAno[5];
	int vetMes=0, vetAno=0;
	int iDia, iMes, iAno;
	int i, j, k;
	
	for (i=0; data[i]!= '/'; i++) {
		sDia[i]= data[i];		
	}
	sDia[i]= '\0';
	i++;
	
	iDia= atoi(sDia);
		
	for (j=i; data[j]!= '/'; j++, vetMes++) {
		sMes[vetMes]= data[j];
	}
	sMes[j]= '\0';
	j++;
	
	iMes= atoi(sMes);
/*		
	for (k=j; data[k]!='/'; k++, vetAno++) {
		sMes[vetAno]= data[k];
	}
	
	sAno[k]= '\0';
	
	iAno= atoi(sAno);
	

}

/*
int ehnumero(char c){
	if ((c>=48)||(c<=57))
		return 0;
	else 
		return 1;
}
*/
