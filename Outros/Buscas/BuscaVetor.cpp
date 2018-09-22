#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 7

int vetor[tam];

void gera(){
	int i;
	srand (time(NULL));
	for(i=0; i<tam; i++) vetor[i] = rand()%11;
}

void imprime(){
	for(int i=0; i<tam; i++){
		printf("[ %d ]", vetor[i]);
	}
	printf("\n\n");
}

void moverParaFrente (int valor){
    int i = 0;
    while (i < tam){
        if (valor = vetor[i]){
            while (i>0){
                vetor[i] = vetor [i-1];
                i--;
            }
            vetor[0] = valor;
            return;
        }
        i++;
    }
    printf(" Não achei!\n\n");
}

void transposicao (int valor){
    int i = 0;
    while (i < tam){
        if (valor = vetor[i]){
            if(i!=0){
                int aux = vetor[i-1];
                vetor[i-1] = vetor[i];
                vetor[i] = aux;
                return;
            }
        }
        i++;
    }
    printf("\n Não achei!\n\n");
}

void sequencial (int valor){
    int i = 0;
    while (i < tam){
        if (valor = vetor[i]){
            moverParaFrente(valor);
            printf(" Achei!\n\n");
            return;
        }
        i++;
    }
    printf(" Não achei!\n\n");
}

void sequencialSentinela (int valor){
    int i = 0;
    vetor[tam-1] = valor;
    while(valor!=vetor[i]){
        i++;
    }
    if (i==tam-1) printf(" Não achei!\n\n");
    else printf(" Achei!\n\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    gera();
    imprime();
    sequencial(2);
    imprime();
    system("pause");
    return 1;
}
