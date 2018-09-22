#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 200

int vetor[tam];

void gera(){
	int i;
	srand (time(NULL));
	for(i=0; i<tam; i++) vetor[i] = rand();
}

void sequencialSentinela (int valor){
    int i = 0;
    vetor[tam-1] = valor;
    while(valor!=vetor[i]){
        i++;
    }
    if (i==tam-1) printf("N�o achei!\n\n");
    else printf("Achei!\n\n")

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    gera();
    sequencialSentinela(7);
    system("pause");
    return 1;
}
