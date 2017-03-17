	#define TAM 5

	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctime>
	#include <clocale>
	#include <unistd.h>


	using namespace std;

	void push();
	void menu();
	void pop();
	void imprimePilha();
    bool vazia();

	int pilha[TAM];
	int topo = -1;

	int main() {
		setlocale(LC_ALL, "portuguese");
        menu();
        printf("Data: %s\nHora: %s\n\n\n",__DATE__,__TIME__);
        return 1;
	}

	void push(int valor) {
	    int val;

	    cout << "Push Mode\n";

	    if(topo == TAM-1) {
	        printf("Pilha cheia!\n");
	        return;
	    }

	    topo++;

	    cout << "Insira um valor para empilhar: ";
	    cin >> valor;
	    fflush(stdin);
	    pilha[topo] = valor;

        //system("clear");
        system("cls");
	    cout << "Push Mode\n";
	    printf("Sucesso!\n");
	}


	void pop () {
        if(topo == 0)
            printf("Pilha vazia!\n");
	    if(topo == -1) {
	        printf("Pilha vazia!\n");
	        return;
	    }
	    else {
            pilha[topo] = 0;
	    }
        topo--;
	}

	void menu () {
	    int esc;
	    printf("-------------------------------\n");
	    printf("-  Para fazer \"Push\" insira 1 -\n");
        printf("-------------------------------\n");
	    printf("-  Para fazer \"Pop\"  insira 2 -\n");
	    printf("-------------------------------\n");
	    printf("-  Para sair insira 0         -\n");
   	    printf("-------------------------------\n");
   	    printf("Valor: ");
	    scanf("%i", &esc);
	    fflush(stdin);
	    //system("clear");
	    system("cls");
	    switch (esc) {
	    case 1:
	        push(1);
	        break;
	    case 2:
	        pop();
	        break;
        case 0:
            return;
            break;
	    default:
	        printf("VALOR INCORRETO, SEU ANIMAL.\n");
	        menu();
	    }
	    imprimePilha();
	    menu();
	}

    void imprimePilha() {
        for(int i=TAM-1; i>=0; i--) {
            printf("  -----------------------\n");
            if(i == topo)
                printf("  | %2i | %10i | * |\n", i+1, pilha[i]);
            else
                printf("  | %2i | %10i |   |\n", i+1, pilha[i]);

        }

        printf("  -----------------------\n");

        printf("\n  O topo está em %i\n\n", topo+1);

        sleep(4);
        //system("clear");
        system("cls");
    }
