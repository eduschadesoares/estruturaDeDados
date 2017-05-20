    #include <iostream>
    #include <clocale>
    #include <ctime>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <conio2.h>

    const int TAM = 5;

    int fila[TAM];
    int inicio = 0;
    int fim = 0;
    int contador = 0;

    using namespace std;

    void menu();
    void menuInsere();
    void insereFila();
    void removeFila();
    void imprimeFila();

    int main() {
        menu();
        return 0;
    }

    void insereFila(int valor) {
        if(contador == TAM) {
            cout << "  Fila cheia\n";
            return;
        }
        fila[fim] = valor;
        if(fim == TAM-1)
            fim = 0;
        else
            fim++;
        contador++;
    }

    void menuInsere() {
        int valor;
        cout << "  Insira um valor: ";
        cin >> valor;
        insereFila(valor);
    }

    void removeFila() {
        if(contador == 0) {
            cout << "  Fila vazia\n";
            return;
        }
        if(inicio == TAM-1)
            inicio = 0;
        else inicio=inicio + 1;
        contador--;
    }

    void imprimeFila() {
        int i, j;
        if(contador == 0) {
            printf("  Fila vazia\n");
            return;
        }
        j=inicio;
        for(i=0; i<contador; i++){
            printf("  %d\t", fila[j]);
            if(j == TAM-1)
                j=0;
            else j=j+1;
        }
        cout << "\n";
    }

    void menu () {
	    setlocale(LC_ALL, "portuguese");
	    char esc;
	    printf("  ----------------------------------\n");
	    printf("  - Para Inserir na fila, insira 1 -\n");
        printf("  ----------------------------------\n");
	    printf("  - Para Remover da fila, insira 2 -\n");
	    printf("  ----------------------------------\n");
	    printf("  - Para sair insira 0             -\n");
   	    printf("  ----------------------------------\n");
   	    printf("  Valor: ");
   	    esc = getch();
	    //scanf("%i", &esc);
	    fflush(stdin);
	    system("cls");
	    switch (esc) {
	    case '1':
	        menuInsere();
	        break;
	    case '2':
	        removeFila();
	        break;
        case '0':
            return;
            break;
	    default:
	        printf("  VALOR INCORRETO, SEU ANIMAL.\n");
	        menu();
	    }
	    imprimeFila();
	    menu();
	}

