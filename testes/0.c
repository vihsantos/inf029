#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* int main (){
		
		char sdata[15];
		int data;
		
		strcpy(sdata, "10/06/2000");
		
			data= atoi(sdata);
			
			printf("%d ", data);
			
	return 0;
}

 O QUE EU PERCEBI:

>>>>> A FUN��O ATOI S� PEGOU OS DOIS PRIMEIROS N�MEROS E DESCONSIDEROU O RESTO, ELA PAROU NA BARRA!
>>>>> SEPARA��O DA STRING COM O FOR VAI CONTER ISSO!!!!
*/

int main () {
	
	char sdata[11];
	
	strcpy(sdata, "10a/06/2000");
	
	
	return 0;
}
