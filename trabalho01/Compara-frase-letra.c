#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	char frase[250], letra;
	
	printf("Insira uma frase\n");
	gets(frase);
	
	printf("Insira uma letra\n");
	letra = getchar();
	
	int x=0, cont=0;
	
	for (x=0; x<strlen(frase); x++){
		if (frase[x]==letra)
			cont++;
	}
	
	printf("A letra %c aparece %d vezes", letra, cont);
	
	return 0;
}
