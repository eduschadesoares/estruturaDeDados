#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 20

int vetor[tam];

void gera(){
	int i;
	srand (time(NULL));
	for(i=0; i<tam; i++) vetor[i] = rand();
}

void geraOrdenado(){
	int i;
	for(i=0; i<tam; i++) vetor[i] = i+1;
}

void imprime(){
	for(int i=0; i<tam; i++){
		printf("[%d]\n", vetor[i], i+1, tam);
	}
}

void sequencial (int valor){
    int i=0;
    while (i < tam && valor >= vetor[i]){
        if (valor == vetor[i]){
            printf("Achei!");
            return;
        }
        i++;
    }
    printf("N�o achei!");
}

void sequencialS (int valor){
	int i=0;
	vetor[tam-1] = valor;
	while (vetor[i] < valor) i++;
	if (i==tam-1 || vetor[i]!=valor) printf("N�o achei!");
	else printf("Achei!");
}

void binaria (int valor){
    int inicio = 0;
    int fim = tam-1;
    int meio;
    int contadorBin;
    while(meio!=inicio && meio!=fim){ // ou while (inicio <= fim)
        meio = (inicio + fim)/2;
        contadorBin++;
        /*switch(valor){
            case < meio:

        }*/
        if (valor == vetor[meio]) {
                printf("Achei!\n");
                return;
        }
        if (valor < vetor[meio]) fim = meio-1;
        else /* valor > vetor[meio] */ inicio = meio+1;
    }
    printf("N�o achei!\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
//    gera();
    geraOrdenado();
    binaria(35);
    imprime();
    system("pause");
    return 0;
}
