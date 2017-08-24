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
    char nomeArquivoAbrir[TAM];  //Nome do arquivo para ser aberto

	struct no {
	    char dado[TAM];
	    int contador;
	    struct no *esq;
	    struct no *dir;
	};

	struct no *raiz = NULL;

	void menuOpcoes();
	void msgmCarregarArquivo();
	void msgmCarregarArquivo2();
	void msgmFailArquivo();
	void nomeArquivo();

	void insereArvore(char palavra[]){
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

        cout << "  Aguarde, as palavras estão sendo inseridas na árvore\n";
        system("cls");

	    while(atual != NULL){
	        anterior = atual;
	        if(strcmp(atual -> dado,palavra) == 0) {
                atual -> contador = atual -> contador + 1;
                cout << "  Aguarde, as palavras estão sendo inseridas na árvore.\n";
                system("cls");
//	            cout << "  " << endl << "  A palavra \"" << atual -> dado //Mostra se existem palavras sendo inseridas
//	            << "\" foi inserida " << atual -> contador << " vezes na árvore." << endl; //mais de uma vez na árvore
	            delete(aux);
	            return;
	        }
	        if(strcmp(palavra,atual -> dado) < 0) {
                cout << "  Aguarde, as palavras estão sendo inseridas na árvore....\n";
                system("cls");
                atual = atual -> esq;
	        }else {
                cout << "  Aguarde, as palavras estão sendo inseridas na árvore.....\n";
                system("cls");
	            atual = atual -> dir;
	        }
	    }
	    if (strcmp(anterior -> dado,palavra) > 0) {
            cout << "  Aguarde, as palavras estão sendo inseridas na árvore...\n";
            system("cls");
            anterior -> esq = aux;
        }
	    else anterior -> dir = aux;
            cout << "  Aguarde, as palavras estão sendo inseridas na árvore..\n";
            system("cls");

	}

	void busca (char palavra[]){  //Busca por uma palavra na árvore
	    struct no *atual;
	    atual = raiz;
	    while (atual != NULL){
	        if(strcmp(palavra, atual -> dado) == 0){
	        	if(atual -> contador == 1) {
                    cout << "  Palavra \"" << palavra << "\" foi encontrada " << atual -> contador << " vez." << endl;
				}
				if(atual -> contador > 1) {
                    cout << "  Palavra \"" << palavra << "\" foi encontrada " << atual -> contador << " vezes." << endl;
				}
	            return;
	        }
	        if(strcmp(palavra,atual->dado) < 0) {
                atual = atual -> esq;
	        } else {
                atual = atual -> dir;
	        }
	    }
	    cout << "  A palavra \"" << palavra << "\" não foi encontrada na árvore." << endl;
	}

	void emOrdem (struct no *atual){ //Ordena a impressão da árvore
	    if(atual != NULL){
	        emOrdem(atual -> esq);
	        if(atual -> contador >= contRepeticao) { //Recebe a qntd de repetições da palavra
                contRepeticao = atual -> contador;   //cuja maior qntd for encontrada
	        }
            printf("  | %27s | %3d |\n", atual -> dado, atual -> contador);
            printf("  -------------------------------------\n");
	        emOrdem(atual -> dir);
	    }
	}

	void maisRepetido (struct no *atual) {
        if(atual != NULL) {
            maisRepetido(atual -> esq);
			if (contRepeticao == atual -> contador) { //Quando o contador encontra a palavra mais repetida
                strcpy(palavraAux, atual -> dado);    //ele printa qual é a palavra
                if(contRepeticao == 1) {
				cout << "  - Palavra mais encontrada na árvore  \n  - foi \"" << palavraAux << "\"" << endl;
				cout << "  - encontrada " << contRepeticao << " vez" << endl;
                } else {
				cout << "  - Palavra mais encontrada na árvore  \n  - foi \"" << palavraAux << "\"" << endl;
				cout << "  - encontrada " << contRepeticao << " vezes" << endl;
                }
			}
            maisRepetido(atual -> dir);
		}
	}

	void toLower(char palavra[]) {              //Transforma todas as palavras inseridas em minúsculas
		for(int i=0; palavra[i] != '\0'; i++) { //e altera na variável global palavra[]
			palavra[i] = tolower(palavra[i]);
		}
	}

	void inserePalavra() {  //Insere palavras na árvore
        printf("  -------------------------------------\n");
        printf("  -         INSERIR NA ÁRVORE         -\n");
        printf("  -------------------------------------\n");
	   	printf("  - Insira uma palavra:               -\n");
        printf("  -------------------------------------\n");
	   	printf("  - ");
		cin >> palavra;
		fflush(stdin);      //Se o usuario inserir uma palavra será chamada a função toLower()
		toLower(palavra);   //sendo passada como parametro a palavra inserida pelo usuário
		system("cls");
        cout << "  \"" << palavra << "\" inserido com sucesso na árvore!" << endl;
	}

    void leArquivo() { //Faz a leitura do arquivo
    	FILE *fp;
    	char palavraTemp[TAM], c; //Variável para armazenar temporariamente a palavra lida no arquivo
	    fp = fopen(nomeArquivoAbrir,"r");  //Abre o arquivo com o nome padrão "arquivo"
	    if (fp == NULL){ //Testa se foi possível abrir o arquivo para leitura
//	        cout << "  Erro! Não foi possível abrir o arquivo." << endl;
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

	void nomeArquivo() {
        printf("  -------------------------------------\n");
	    printf("  - Insira o nome do arquivo que      -\n");
	    printf("  - deseja abrir seguido de \".txt\"    -\n");
	    printf("  -------------------------------------\n");
	    printf("  - O arquivo deve estar no mesmo     -\n");
	    printf("  - diretório do projeto              -\n");
        printf("  -------------------------------------\n");
        printf("  - ");
    	cin >> nomeArquivoAbrir;
    	fflush(stdin);
    	system("cls");
	}

	bool verificaArquivo() {
        FILE *fp;
    	char palavraTemp[TAM], c; //Variável para armazenar temporariamente a palavra lida no arquivo
	    fp = fopen(nomeArquivoAbrir,"r");  //Abre o arquivo com o nome padrão "arquivo"
	    if (fp == NULL){ //Testa se foi possível abrir o arquivo para leitura
	       return false;
	    } else {
            return true;
	    }
	}

	void msgmFailArquivo() {
        char esc;
        printf("  -------------------------------------\n");
        printf("  -                ERRO               -\n");
        printf("  -------------------------------------\n");
	    printf("  - Parece que não existe nenhum      -\n");
	    printf("  - arquivo salvo com esse nome no    -\n");
	    printf("  - diretório                         -\n");
	    printf("  -------------------------------------\n");
        printf("  - Pressione qualquer tecla para     -\n");
        printf("  - continuar                         -\n");
        printf("  -------------------------------------\n  ");
        esc = getche();
        system("cls");
        return;
	}

	void msgmCarregarArquivo2() {
        char esc;
        printf("  -------------------------------------\n");
	    printf("  - O arquivo \"arquivo.txt\" salvo     -\n");
	    printf("  - na pasta padrão do projeto será   -\n");
	    printf("  - aberto. Deseja continuar?         -\n");
	    printf("  -------------------------------------\n");
        printf("  - Digite S (sim) ou N (não):        -\n");
        printf("  -------------------------------------\n  ");
        esc = getche();
        fflush(stdin);
        system("cls");
        switch (esc) {
        case 'S':
//            leArquivo();
            break;
        case 's':
//            leArquivo();
            break;
        case 'N':
            msgmCarregarArquivo();
            break;
        case 'n':
            msgmCarregarArquivo();
            break;
        default:
            printf("  -------------------------------------\n");
	        printf("  - Opção incorreta. Tente novamente! -\n");
	        msgmCarregarArquivo2();
        }
	}

	void msgmCarregarArquivo() {
	    char esc;
        printf("  -------------------------------------\n");
	    printf("  - Deseja carregar arquivo de texto  -\n");
	    printf("  - para inserção na árvore?          -\n");
	    printf("  -------------------------------------\n");
        printf("  - Digite: S (sim) ou N (não):       -\n");
        printf("  -------------------------------------\n  ");
        esc = getche();
        fflush(stdin);
        system("cls");
        switch (esc) {
        case 'S':
            nomeArquivo();
            if(verificaArquivo()) {
                leArquivo();
            } else {
                msgmFailArquivo();
            }
            break;
        case 's':
            nomeArquivo();
            if(verificaArquivo()) {
                leArquivo();
            } else {
                msgmFailArquivo();
            }
            break;
        case 'N':
            menuOpcoes();
            break;
        case 'n':
            menuOpcoes();
            break;
        default:
            printf("  -------------------------------------\n");
	        printf("  - Opção incorreta. Tente novamente! -\n");
	        msgmCarregarArquivo();
        }
	}

	bool verificaVazio() {
	    if(raiz == NULL) {
            return true;
	    } else {
            return false;
	    }
	}

    void menuOpcoes () {
	    char esc;
	    printf("  -------------------------------------\n");
	    printf("  -           ÁRVORE BINÁRIA          -\n");
	    printf("  -------------------------------------\n");
	    printf("  -  1  |  Imprimir a arvore          -\n");
        printf("  -------------------------------------\n");
   	    printf("  -  2  |  Buscar na arvore           -\n");
	    printf("  -------------------------------------\n");
   	    printf("  -  3  |  Inserir manualmente        -\n");
	    printf("  -------------------------------------\n");
        printf("  -  4  |  Carregar de um arquivo     -\n");
	    printf("  -------------------------------------\n");
	    printf("  -  0  |  Sair                       -\n");
   	    printf("  -------------------------------------\n");
   	    printf("  - Valor: ");

   	    //Com a utilização da biblioteca <conio.h> (Sem enter)
   	    esc = getche();

   	    //Com a utilização da biblioteca padrão (Com enter)
	    //scanf("%c", &esc);

	    fflush(stdin);
	    //system("clear"); (Para linux)
	    system("cls");
	    switch (esc) {
	    case '1':
	        if(!verificaVazio()) {
                printf("  -------------------------------------\n");
                printf("  |           PALAVRA           | QTD |\n");
                printf("  -------------------------------------\n");
                emOrdem(raiz);
                maisRepetido(raiz);
	        } else {
            printf("  -------------------------------------\n");
	        printf("  -           ÁRVORE VAZIA!           -\n");
	        }
	        break;
        case '2':
            if(!verificaVazio()) {
                inserePalavra();
                busca(palavra);
            } else {
                printf("  -------------------------------------\n");
                printf("  -           ÁRVORE VAZIA!           -\n");
            }
	        break;
        case '3':
	    	inserePalavra();
	    	insereArvore(palavra);
            break;
        case '4':
            msgmCarregarArquivo();
            break;
        case '0':
            return;
            break;
	    default:
            printf("  -------------------------------------\n");
	        printf("  - Opção incorreta. Tente novamente! -\n");
	        menuOpcoes();
	    }
	    //Faz um loop do menu até o usuário sair
	    menuOpcoes();
	}

	int main(){
		setlocale(LC_ALL, "Portuguese");
	    menuOpcoes();
		return 0;
	}
