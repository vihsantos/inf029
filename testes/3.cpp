#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar_data(char data []); 
int validando_data(int dia, int mes, int ano);
int ehnumero (char c);

int main(){
	
	char data[13];
	
	strcpy(data, "10/06/2000");
	
	int resul = validar_data(data);
	
		if (resul==0)
			printf("Data valida\n");
		else
			printf("Data invalida\n");
	
	return 0;	
}

int validar_data(char data []){
	
	char sDia[3], sMes[3], sAno[5];
	int iDia, iMes, iAno;
	
	int i;
	for(i=0; data[i]!='/'; i++){
		sDia[i]=data[i];
			
			if (i>1) 
				return 1;
				
		/*	if (!ehnumero(sDia[i]))
				return 1;
				*/
	}
		iDia= atoi(sDia);
		
		i++;
	
	int j, cont=0;
	for (j=i; data[j]!= '/'; j++, cont++){
		sMes[cont]=data[j];
			
			if (cont>1)
				return 1;
				
	/*		if (!ehnumero(sMes[j]))
				return 1;
	*/

	}
		iMes= atoi(sMes);
			
	j++;
	
	int k, cont2=0;
	for (k=j; data[k]!= '/'; k++, cont2++){
		sAno[cont2]=data[k];
		
	/*	if (!ehnumero(sAno[k]))
				return 1;
	*/
	}
		iAno= atoi(sAno);
		
		return validando_data(iDia, iMes, iAno);
	
}

int validando_data(int dia, int mes, int ano){
	
	if ((dia<1)&&(dia>31))
		return 1;
	
	if ((mes<1)&&(mes>12))
		return 1;
		
		return 0;
}

int ehnumero (char c){
	if ((c>=48)&&(c<57))
		return 0;
}
