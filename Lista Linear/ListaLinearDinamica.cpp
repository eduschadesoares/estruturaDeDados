    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctime>
    #include <clocale>
    #include <ctime>
    #include <conio.h> //Para a utilização da função getche()


	using namespace std;

    //Procedimentos principais
    void insereLista();
    void removeLista();
    void recuperaLista();
    void buscaLista();
    void imprime();
    void preencheLista();
    void menu();

    void menuInsereLista();
    void menuRemoveLista();
    void menuRecuperaLista();
    void menuBuscaLista();

	int tamanho = 0;
	
	struct no {
        int dado;
        struct no *prox;
	};
    struct no *lista = NULL;



    int main () {
        setlocale(LC_ALL,"");
        cout << "  Lista linear dinâmica" << endl;
        menu();
		cout << "  Eduardo Soares - 16016923\n";
        cout << "  Matheus Gomes  - 16267723\n";
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
        printf("  Número %2i foi inserido com sucesso!\n", valor);
        tamanho++;
        //cout << "  Número " << valor << " foi inserido com sucesso!\n";
	}

	void removeLista(int posicao) {
        struct no *atual;
        struct no *anterior;
        int cont = 1;
   	    atual = lista;

        if(lista == NULL) {
            cout << "  Lista vazia!\n";
            return;
        }
		
		if (posicao == 1) {
        	lista = lista->prox;
        	delete(atual);
        	cout << "  Número removido com sucesso!\n";
        	return;
    	}
		
		while(cont != posicao) {
  	    	if (atual->prox == NULL) {
            	cout << "  Posição inválida!\n";
           	    return;
        	}
     	 	anterior = atual;
			atual = atual->prox;		
			cont++;
		}
		
 	    anterior->prox = atual->prox;
    	delete(atual);
    	cout << "  Número removido com sucesso!\n";
    } 

	void recuperaLista(int posicao) {
		struct no *aux;
		aux = lista;
		
		if (lista == NULL) {
			cout << "  Não é possível buscar por nenhuma posição, a lista está vazia!\n";
			return;			
		}
		
		for (int i = 1; i < posicao; i++) {
			if(aux -> prox == NULL) {
				cout << "  Posição inválida\n";
				return;				
			}
			aux = aux -> prox;		
		}		
		cout << "  O valor encontrado na posição " << posicao << " é: " << aux -> dado << "\n";
	}
	
	void buscaLista(int valor) {
  	  	struct no *aux;
        aux = lista;
        int i = 1, qntd = 0;        
        
    	if (lista == NULL) {
     	 	 cout << "  Lista vazia!\n";
			 return;
    	}
    	
    	while (aux != NULL) {
	        if (aux->dado == valor) {
	            cout << "  O número " << valor << " foi encontrado na posição: " << i << "\n";
	            qntd++;
	        }
	        aux = aux->prox;
	        i++;        
    	}	  	  
		  
    	if(qntd == 0)
  			cout << "  O número não foi encontrado na lista! =/\n";
   			else if (qntd == 1)
   					cout << "  O número " << valor << " foi encontrado " << qntd << " vez.\n";
    				else
		    			cout << "  O número " << valor << " foi encontrado " << qntd << " vezes.\n";		
	}
	
    void preencheLista() {
    	int qntd, valor;
    	cout << "  Quantidade de posições a serem preenchidas: ";
    	cin >> qntd;
    	fflush(stdin);   	
		srand(time(NULL));
        for(int i = 0; i < qntd; i++) {
            valor = rand() % 9-0;
            insereLista(valor);
        }
        cout << "  A lista de tamanho " << qntd << " foi automaticamente preenchida!\n";	
	}
	
    void imprime() {
    	int i=0;
        struct no *aux;
        if(lista == NULL) {
            cout << "  Lista Vazia!\n";
            return;
        }
        aux = lista;
       	printf("  -------------------\n");
        printf("  | P. |  VALORES   |\n");
        printf("  -------------------\n"); 
        while (aux != NULL) {
        	i++;
            printf("  | %2i | %10i |\n", i, aux -> dado);
			printf("  -------------------\n");
            aux = aux -> prox;
        }
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

	void menuRecuperaLista() {
		int posicao;
    	cout << "  Insira uma posição: ";
        cin >> posicao;
        fflush(stdin);
        recuperaLista(posicao);		
	}
	
	void menuBuscaLista() {
		int valor;
    	cout << "  Insira um valor para buscar na lista: ";
        cin >> valor;
        fflush(stdin);
        system("cls");
        buscaLista(valor);
		
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
            menuBuscaLista();
            break;
        case '4':
	        menuRecuperaLista();
	        break;
        case '5':
	        imprime();
	        break;
        case '6':
            preencheLista();
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

