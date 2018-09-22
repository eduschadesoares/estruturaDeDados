#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 7

int vetor[tam];

struct no{
    int dado;
    struct no *prox;
};
struct no *lista = NULL;

void gera(){
	int i;
	srand (time(NULL));
	while(i<10) {
        aux = new(struct no);
        aux -> dado = i;
        aux -> prox = lista;
        lista = aux;
        i++;
	}
}

void imprime(){
	for(int i=0; i<tam; i++){
		printf("[ %d ]", vetor[i]);
	}
	printf("\n\n");
}

void sequencial (int valor) {
    struct no *atual;
    atual = lista;
    while(atual != NULL){
        if(valor == atual -> dado){
            printf("Achei!");
            return;
        }
        atual = atual -> prox;
    }
    printf("N�o achei!");
}

void moverParaFrente(int valor){
    struct no *atual, *anterior;
    atual = lista;
    while(atual != NULL) {
        if(valor == atual -> dado){
            printf("Achei!");
            if(atual!=lista){
                anterior -> prox = atual -> prox;
                atual -> prox = lista;
                lista =atual;
            }
            return;
        }
        anterior = atual;
        atual = atual -> prox;
    }
    printf("N�o achei!");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    gera();
    imprime();
    moverParaFrente;
    imprime();
    system("pause");
    return 1;
}
