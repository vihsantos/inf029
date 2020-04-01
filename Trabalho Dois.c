#include <stdio.h>
#include <stdlib.h>

void inicia_vet(int *pontvet){
  int x;
    for(x=0; x<10; x++){
      pontvet[x]= -1;
    }
}

/*void listar_vet(int *pontvet){
   int x;
    for(x=0; x<10; x++){
      printf("%d ",pontvet[x]);
    }
}
*/

int inserir_um_elemento(int *pontvet, int pos, int n){
	if(pos<10){
		if(pontvet[pos]==-1){
		pontvet[pos]= n;
		return 0;
		}
		else {
			return 1;
		}
	}
	else{
		return 1;
	}
}

int inserir_est_aux (int *pontvet, int pos, int quantvet){
	if (pos<10){
		
	}
	else {
		return 1;
	}
	
}

// essa função excluir está errada, é so pra ter uma idéia de como vai ficar

int excluir_elemento(int *pontvet, int pos, int elem){
	if (pos<10){
		pontvet[pos]=-1;
		return 0;
	}
	else {
		return 1;
	}
}

// int aumentar_aux (int *pontvet, int pos)


int main (){
  int vet[10], x, cod;
  int *pvet= vet;

      inicia_vet(pvet);

    printf("TRABALHO DOIS\n");
    printf("DIGITE 1 PARA INSERIR ELEMENTO.\n DIGITE 2 PARA LISTAR TODAS AS ESTRUTURAS.\n DIGITE 3 PARA LISTAR OS NUMEROS ORDENADOS DAS ESTRUTURAS AUXILIARES.\n DIGITE 4 PARA LISTAR TODOS OS NUMEROS ORDENADOS.\n DIGITE 5 PARA EXCLUIR UM ELEMENTO.\n DIGITE 6 PARA AUMENTAR O TAMANHO DA ESTRUTURA AUXILIAR.\n DIGITE 7 PARA SAIR.\n");
    scanf("%d", &cod);
    
    	switch (cod){
    		case 1: {
    			int res, p, e, rstd;
				
				printf("DIGITE 1 SE DESEJA INSERIR APENAS UM ELEMENTO. \n DIGITE 2 SE DESEJA INCREMENTAR UMA ESTRUTURA AUXILIAR.")
    			scanf("%d", &res)
    			
    			if (res==1){
    				printf("Insira a posição em que deseja colocar o seu elemento\n");
    				scanf("%d", &p)
    				printf("Insira o seu elemento\n");
    				scanf("%d", &e)
    				
    				rstd= inserir_um_elemento(pvet, p, e);
    				
				}
    			
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				break;
			}
			case 5: {
				break;
			}
			case 6: {
				break;
			}
			case 7: {
				break;
			}
		}
  
  return 0;
}
