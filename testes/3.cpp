#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	char data[13];
	
	strcpy(data, "10/06/2000");
	
	
	char sDia[3], sMes[3], sAno[5];
	int iDia, iMes, iAno;
	
	int i;
	for(i=0; data[i]!='/'; i++){
		sDia[i]=data[i];
	}
		iDia= atoi(sDia);
		
		i++;
	
	int j, cont=0;
	for (j=i; data[j]!= '/'; j++, cont++){
		sMes[cont]=data[j];
	}
		iMes= atoi(sMes);
			
	j++;
	
	int k, cont2=0;
	for (k=j; data[k]!= '/'; k++, cont2++){
		sAno[cont2]=data[k];
	}
		iAno= atoi(sAno);
		
		printf("%d", iAno);

	return 0;	
}

