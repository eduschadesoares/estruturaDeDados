	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctime>
	#include <clocale>
	#include <unistd.h>


	using namespace std;


	struct no {
        int dado;
        struct no *prox;
	};
	struct no *topo = NULL;

	void pushMenu();

    void push(int valor) {
        struct no *aux;
        aux = new(struct no);
        aux -> dado = valor;
        aux -> prox = topo;
        topo = aux;
    }

    void imprime() {
        struct no *aux;
        if(topo == NULL) {
            cout << "  Pilha Vazia\n";
            return;
        }
        aux = topo;
        while (aux != NULL) {
            //cout << "%d \n" << aux -> dado;
            printf(" %d \n", aux -> dado);
            aux = aux -> prox;
        }
    }

    void pushMenu() {
        int esc;
        cout << "  Insira um valor: ";
        cin >> esc;
        push(esc);
        pushMenu();
    }

	int main () {
        pushMenu();
	    imprime();
        return 0;
	}


