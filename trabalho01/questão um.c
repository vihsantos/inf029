#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validador_de_data (char data[]);
int valida_data(int Dia, int Mes, int Ano);
int ehnumero(char c);

int main (){
	
	char data[15];
	int retorno;
	strcpy(data, "10/06/5");
	
	retorno= validador_de_data(data);
	
	if (retorno==1){
		printf("Data invalida");
	}
	else {
		printf("Data valida");
	}
	
	return 0;
}

int validador_de_data (char data[]){
	
	char sDia[3], sMes[3], sAno[5];
	int vetMes=0, vetAno=0;
	int iDia, iMes, iAno;
	int i, j, k;
	int ret;
	
	for (i=0; data[i]!= '/'; i++) {
		sDia[i]= data[i];
		
		if (i>1) return 1;
		if(ehnumero(sDia[i])==1)return 1;
				
	}
	sDia[i]= '\0';
	i++;
	
	iDia= atoi(sDia);
		
	for (j=i; data[j]!= '/'; j++, vetMes++) {
		sMes[vetMes]= data[j];
		
		if (vetMes>1) return 1;
		if(ehnumero(sMes[vetMes])==1)return 1;
		
	}
	sMes[j]= '\0';
	j++;
	
	iMes= atoi(sMes);
	
	for (k=j; k < strlen(data); k++, vetAno++) {
			sAno[vetAno]= data[k];
			
			if(vetAno>1) return 1;
			
			if(ehnumero(sAno[vetAno])==1)return 1;
		}
	
		sAno[k]= '\0';
	
	iAno = atoi(sAno);
	
	if((iAno>=0)&&(iAno<=99)){
		iAno=iAno+2000;
	}
	
	printf("%d/%d/%d\n", iDia, iMes, iAno);
	
	ret=valida_data(iDia, iMes, iAno);
	
	return ret;
}

int valida_data(int dia, int mes, int ano){
	
	if (ano>=1)
		return 0;
	else
		return 1;
		
	if (mes>=1 || mes<=12)
		return 0;
	else	
		return 1;
		
	if (dia>=1 || dia<=31 && (mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12))
		return 0;
	else if (dia>=1||dia<=30&&(mes==4)||(mes==6)||(mes==9)||(mes==11))
		return 0;
	else
		return 1;
		
	if (dia>=1 || dia<=28&&(mes==2))	
		return 0;
	else if ((dia==29)&&(mes==2)&&(ano%4==0 &&ano%100!= 0))
		return 0;
	else 
		return 1;
}

int ehnumero(char c){
	if (c>=48 && c<=57)
		return 0;
	else	
		return 1;
}



