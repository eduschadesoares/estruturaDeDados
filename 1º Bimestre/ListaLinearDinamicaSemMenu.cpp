    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctime>
    #include <clocale>
    #include <ctime>

	using namespace std;

    void insereLista(int valor);
    void removeLista(int posicao);
    void recuperaLista(int posicao);
    void buscaLista(int valor);
    void imprime();

	int tamanho = 0;
	
	struct no {
        int dado;
        struct no *prox;
	};
    struct no *lista = NULL;

    int main () {
        setlocale(LC_ALL,"");
        cout << "  Lista linear dinâmica" << endl;
		insereLista(5);  //Insere um valor na lista
		insereLista(8);
    	imprime();  //Imprime lista
   	    recuperaLista(1);  //Verifica o valor em determinada posição
    	buscaLista(5);  //Busca se o valor existe na lista 
   	    removeLista(1);  //Remove um valor na lista
    	imprime();
		cout << "  Eduardo Soares - 16016923" << endl;
        cout << "  Matheus Gomes  - 16267723" << endl;
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

