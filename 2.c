#include <stdio.h>
#include <stdlib.h>

int contagem_de_digitos(int num);

	int main(){

 	int valor; 
 	scanf("%d", &valor);
 	
 	
  return 0;
}

int contagem_de_digitos(int num ){
	int contaDigitos=0;
	 
       if (num==0) 
	   		contaDigitos = 1;
       else
           while (num!= 0)
          {
              contaDigitos= contaDigitos+1;
              num= num/10;
          }
      printf("%d\n", contaDigitos);
		return contaDigitos;
}

int revertendo_inteiro(int numero){
	
	int n, x, v;
	char inv[10];
	
	n=contagem_de_digitos(numero);
	
	for (x=0; x<=n; x++){
		v= numero%10;
		sprintf(inv, "%d", v);
	}	
}
