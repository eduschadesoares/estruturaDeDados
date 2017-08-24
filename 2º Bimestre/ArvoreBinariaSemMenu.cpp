	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <string.h>
	#include <iostream>
	#include <locale.h>
	#include <ctype.h>

	using namespace std;

	const int TAM = 50;
	char palavra[TAM];
    char palavraAux[TAM];  //Variável auxiliar para guardar a palavra mais usada
    int contRepeticao; //Variável para controle de quantas vezes a palavra foi inserida

	struct no {
	    char dado[TAM];
	    int contador;
	    struct no *esq;
	    struct no *dir;
	};

	struct no *raiz = NULL;

	void insereArvore(char palavra[]){ //Inserir palavra na árvore
		struct no *atual;
	    struct no *anterior;
	    struct no *aux;

	    aux = new(struct no);
	    strcpy(aux -> dado, palavra);
	    aux -> esq = NULL;
	    aux -> dir = NULL;
	    aux -> contador = 1;

	    if (raiz == NULL){
	        raiz = aux;
	        contRepeticao = raiz -> contador; //Variável contador inicializa com a quantidade de
	        return;                           // palavras inseridas na raiz
	    }

	    atual = raiz;

	    while(atual != NULL){
	        anterior = atual;
	        if(strcmp(atual -> dado,palavra) == 0) {
                atual -> contador = atual -> contador + 1;
//	            cout << "  " << endl << "  A palavra \"" << atual -> dado //Mostra se existem palavras sendo inseridas
//	            << "\" foi inserida " << atual -> contador << " vezes na árvore." << endl; //mais de uma vez na árvore
	            delete(aux);
	            return;
	        }
	        if(strcmp(palavra,atual -> dado) < 0) {
                atual = atual -> esq;
	        }else {
	            atual = atual -> dir;
	        }
	    }
	    if (strcmp(anterior -> dado,palavra) > 0) {
            anterior -> esq = aux;
        }
	    else anterior -> dir = aux; {
            cout << "  Aguarde, as palavras estão sendo inseridas na árvore";
            system("cls");
	    }
	}

	void emOrdem (struct no *atual){ //Ordena a impressão da árvore
	    if(atual != NULL){
	        emOrdem(atual -> esq);
	        if(atual -> contador >= contRepeticao) { //Recebe a qntd de repetições da palavra
                contRepeticao = atual -> contador;   //cuja maior qntd for encontrada
	        }
            printf("  | %23s | %3d |\n", atual -> dado, atual -> contador);
            printf("  ---------------------------------\n");
	        emOrdem(atual -> dir);
	    }
	}

	void maisRepetido (struct no *atual) {
        if(atual != NULL) {
            maisRepetido(atual -> esq);
			if (contRepeticao == atual -> contador) { //Quando o contador encontra a palavra mais repetida
                strcpy(palavraAux, atual -> dado);    //ele printa qual é a palavra
				cout << "  Palavra mais encontrada na árvore foi \"" << palavraAux << "\", encontrada "
                << contRepeticao << " vezes" << endl;
			}
            maisRepetido(atual -> dir);
		}
	}

	void toLower(char palavra[]) {              //Transforma todas as palavras inseridas em minúsculas
		for(int i=0; palavra[i] != '\0'; i++) { //e altera na variável global palavra[]
			palavra[i] = tolower(palavra[i]);
		}
	}

    void leArquivo() { //Faz a leitura do arquivo
    	FILE *fp;
    	char palavraTemp[TAM], c; //Variável para armazenar temporariamente a palavra lida no arquivo
	    fp = fopen("arquivo.txt","r");  //Abre o arquivo com o nome padrão "arquivo"
	    if (fp == NULL){ //Testa se foi possível abrir o arquivo para leitura
	        cout << "  Erro! Não foi possível abrir o arquivo." << endl;
	        return;
	    }

        int cont = 0;  //Contador auxiliar

        while(!feof(fp)){
            c = getc(fp);   // Le um caractere por caractere no arquivo
            if(!isalpha(c)){      //Verifica se o caractere é válido ou se é algum sinal de pontuação
                palavraTemp[cont] = '\0'; //Se encontrar algum sinal de pontuação ou ponto na leitura
                if(cont > 0) {            //ele insere um final na string, assim separando as palavras
                    for(int i=0; palavraTemp[i] != '\0'; i++) { //faz a copia do que foi armazenado na variável
                        strcpy(palavra, palavraTemp);           //temporária para a variável global
                    }
                    toLower(palavra);   //transforma a palavra lida em minúscula
                    insereArvore(palavra);  //insere a palavra que foi lida e transformada em minúscula na árvore
                }
                cont = 0;  //Contador zera pois foi formada uma palavra
            } else {
                palavraTemp[cont] = c;  //Caso não seja encontrado sinal pontuação ou espaço
                cont++;                 //cada caractere é armazenado na variável temporária
            }                           //e o contador é incrementado
        }
		fclose(fp);  //Fecha o arquivo
	}

	int main(){
		setlocale(LC_ALL, "Portuguese");
    	leArquivo();
    	emOrdem(raiz);
    	maisRepetido(raiz);
		return 0;
	}
