	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctime>
	#include <clocale>
	#include <unistd.h>
	#include <conio2.h>

	const int TAM = 5;

	using namespace std;

	void push();
	void pushMenu();
	void menu();
	void pop();
	void imprimePilha();
	void imprimePilhaCompleto();

	int pilha[TAM];
	int topo = -1;

	int main() {
		setlocale(LC_ALL, "Portuguese");
        menu();
        printf("\nData: %s\nHora: %s\n",__DATE__,__TIME__);
        return 0;
	}

	void push(int valor) {
	    if(topo == TAM-1) {
	        printf("  Pilha cheia!\n");
	        return;
	    }
	    topo++;
	    pilha[topo] = valor;
	}

    void pushMenu() {
        int valor;
        if(topo == TAM-1) {
            cout << "  Pilha cheia!\n";
            return;
        }
        cout << "  Insira um valor para empilhar: ";
        cin >> valor;
        fflush(stdin);
        push(valor);
        imprimePilha();
	}


	void pop () {
        if(topo == 0)
            printf("  Pilha vazia!\n");
	    if(topo == -1) {
	        printf("  Pilha vazia!\n");
	        return;
	    }
	    else {
            pilha[topo] = 0;
	    }
        topo--;
        imprimePilhaCompleto();
	}

	void menu () {
	    char esc;
	    printf("  -------------------------------\n");
	    printf("  -  Para fazer \"Push\" insira 1 -\n");
        printf("  -------------------------------\n");
	    printf("  -  Para fazer \"Pop\"  insira 2 -\n");
	    printf("  -------------------------------\n");
	    printf("  -  Para imprimir insira 3     -\n");
	    printf("  -------------------------------\n");
	    printf("  -  Para sair insira 0         -\n");
   	    printf("  -------------------------------\n");
   	    esc = getch();
	    fflush(stdin);
	    system("cls");
	    switch (esc) {
	    case '1':
	        pushMenu();
	        break;
	    case '2':
	        pop();
	        break;
        case '3':
            imprimePilhaCompleto();
            break;
        case '0':
            return;
            break;
	    default:
	        printf("  VALOR INCORRETO, SEU ANIMAL.\n");
	        menu();
	    }
	    menu();
	    imprimePilha();
	}

    void imprimePilhaCompleto() {
        for(int i=TAM-1; i>=0; i--) {
            printf("  -----------------------\n");
            if(i == topo)
                printf("  | %2i | %10i | * |\n", i+1, pilha[i]);
            else
                printf("  | %2i | %10i |   |\n", i+1, pilha[i]);
        }

        printf("  -----------------------\n");

        //sleep(4);
        //system("clear");
    }

    void imprimePilha() {
        for(int i=topo; i >= 0; i--) {
            printf("  ----------------\n");
            printf("  |  %10i  |\n", pilha[i]);
        }
        printf("  ----------------\n");
    }
