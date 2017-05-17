    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctime>
    #include <clocale>
    #include <ctime>
    #include <conio.h>


	using namespace std;

    void insereLista();
    void removeLista();
    void menu();

    void menuInsereLista();
    void menuRemoveLista();


	struct no {
        int dado;
        struct no *prox;
	};
    struct no *lista = NULL;



    int main () {
        setlocale(LC_ALL,"");
        menu();
        return 0;
    }

	void insereLista(int valor) {
        struct no *atual;
        struct no *anterior;
        struct no *aux;
        atual = lista;

        while(atual != NULL && atual -> dado < valor) {
            anterior = atual;
            atual = atual -> prox;
        }

        aux = new(struct no);
        aux -> dado = valor;
        if(atual == lista) {
            aux -> prox = atual;
            lista = aux;
        } else {
            aux -> prox = atual;
            anterior -> prox = aux;
        }
        cout << "  Número " << valor << " inserido com sucesso!\n";
	}

	void removeLista(int posicao) {
        struct no *atual;
        struct no *anterior;
        int cont = 0;

        if(lista == NULL) {
            cout << "  Lista vazia!\n";
            return;
        }

        atual = lista;

        while(atual!=NULL && atual->dado<=valor) {
            if(valor==atual->dado)
            {
                if(atual==lista)
                    lista=lista->prox;
                else
                {
                    anterior->prox=atual->prox;
                }
                delete(atual);
                cont=1;
                tamanho--;
            }
            if(cont==1)
                atual=anterior->prox;
            else
            {
                anterior=atual;
                atual=atual->prox;
            }
        }
        if(cont==1) {
            cout<<"Elemento removido com sucesso."<<endl;
            return;
        } else
        cout<<"Elemento nao encontrado!"<<endl;
    }

	void imprime() {


	}

    void menuInsereLista() {
        int valor;
        cout << "  Insira um valor para inserir na lista: ";
        cin >> valor;
        fflush(stdin);
        insereLista(valor);
    }

    void menuRemoveLista() {
        int posicao;
        cout << "  Insira uma posição: ";
        cin >> posicao;
        fflush(stdin);
        removeLista(posicao);

    }

    void menu () {
	    char esc;
	    printf("  ------------------------------------------\n");
	    printf("  -  1  |  Para inserir na lista           -\n");
        printf("  ------------------------------------------\n");
   	    printf("  -  2  |  Para remover da lista           -\n");
	    printf("  ------------------------------------------\n");
   	    printf("  -  3  |  Para buscar na lista            -\n");
	    printf("  ------------------------------------------\n");
   	    printf("  -  4  |  Para recuperar lista            -\n");
	    printf("  ------------------------------------------\n");
   	    printf("  -  5  |  Para mostrar lista              -\n");
	    printf("  ------------------------------------------\n");
   	    printf("  -  6  |  Preencher automaticamente lista -\n");
	    printf("  ------------------------------------------\n");
	    printf("  -  0  |  Para sair                       -\n");
   	    printf("  ------------------------------------------\n");
   	    printf("  - Valor: ");

   	    //Com a utilização da biblioteca <conio.h>
   	    esc = getche();

   	    //Com a utilização da biblioteca padrão
	    //scanf("%c", &esc);
	    fflush(stdin);

	    //system("clear");
	    system("cls");
	    switch (esc) {
	    case '1':
	        menuInsereLista();
	        break;
        case '2':
            menuRemoveLista();
	        break;
        case '3':
          //  menuBuscaLista();
            break;
        case '4':
	       // menuRecuperaLista();
	        break;
        case '5':
	      //  imprime();
	        break;
        case '6':
          //  preencheLista();
            break;
        case '0':
            return;
            break;
	    default:
	        printf("  Valor incorreto. Tente novamente!\n");
	        menu();
	    }
	    //Faz um loop do menu até o usuário sair
	    menu();
	}

