#include <stdio.h>
#include <stdlib.h>

int contagem_de_digitos(int num);
int potencia(int base, int expoente);

int main(){

	int valor, invertido=0, n=0;
	scanf("%d", &valor);
	
	n=contagem_de_digitos(valor);
		
	while(valor>=1){
		invertido= invertido +(valor%10)*potencia(10, n-1);
		n--;
		valor=valor/10;	
		}
	
	printf("\n%d", invertido);
	
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

int potencia(int base, int expoente){
	
	int resul=1;
		while(expoente>0){
			resul=resul*base;
			expoente--;
		}
		return resul;
}

