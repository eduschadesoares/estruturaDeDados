
//--------------------------------------------------------
//--------------------------------------------------------
//              All rights to @gomesmat                  -
// Taken from https://github.com/gomesmat/2017-Estrutura -
//--------------------------------------------------------
//--------------------------------------------------------

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

void sequencial (int valor){
    int i = 0;
    while (i < tam){
        if (valor = vetor[i]){
            printf("Achei!\n\n");
            return;
        }
        i++;
    }
    printf("Não achei!\n\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    gera();
    sequencial(7);
    system("pause");
    return 1;
}
