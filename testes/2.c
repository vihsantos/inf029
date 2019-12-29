#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	char data[13];
	
	strcpy(data, "10/06/2000");
	
	int iDia, iMes, iAno;
	char sDia[3], sMes[3], sAno[5];
	
	int i;
	for(i=0; data[i] != '/'; j++){
		sDia[i] = data[i];
	}
	
	iDia= atoi(sDia);
	
	printf("%s", sDia);
	printf("%d", iDia);
	
	

		return 0;
}


