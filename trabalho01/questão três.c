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
		if((frase[x]==65)||(frase[x]==192)||(frase[x]==193)||(frase[x]==194)||(frase[x]==195)||(frase[x]==196)||(frase[x]==197)||(frase[x]==224)||(frase[x]==225)||(frase[x]==226)||(frase[x]==227)||(frase[x]==228)||(frase[x]==229)){
				frase[x]=97;
			}
		if((frase[x]==69)||(frase[x]==200)||(frase[x]==201)||(frase[x]==202)||(frase[x]==203)||(frase[x]==232)||(frase[x]==233)||(frase[x]==234)||(frase[x]==235)){
				frase[x]=101;
			}
		if((frase[x]==73)||(frase[x]==204)||(frase[x]==205)||(frase[x]==206)||(frase[x]==207)||(frase[x]==236)||(frase[x]==237)||(frase[x]==238)||(frase[x]==239)){
				frase[x]=105;
			}
		if((frase[x]==79)||(frase[x]==210)||(frase[x]==211)||(frase[x]==212)||(frase[x]==213)||(frase[x]==214)||(frase[x]==242)||(frase[x]==243)||(frase[x]==244)||(frase[x]==245)||(frase[x]==246)){
				frase[x]=111;
			}
		if((frase[x]==85)||(frase[x]==217)||(frase[x]==218)||(frase[x]==219)||(frase[x]==220)||(frase[x]==249)||(frase[x]==250)||(frase[x]==251)||(frase[x]==252)){
				frase[x]=117;
			}
		
		if (frase[x]==letra){
			cont++;
		}
		}
	
	printf("A letra %c aparece %d vezes", letra, cont);
	
	return 0;
}

