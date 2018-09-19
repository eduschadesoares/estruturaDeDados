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
    void inserefila();
    void removefila();
    void imprimefila();

    int main() {
        menu();
        return 0;
    }

    void inserefila() {
        int valor;

        if(contador == TAM) {
        printf("  |-----------------------|\n");
        printf("  |       FILA CHEIA      |\n");
            return;
        }

        cout << "Insira um valor: ";
        cin >> valor;
        system("cls");

        fila[fim] = valor;

        if(fim == TAM-1)
            fim = 0;
        else
            fim++;

        contador++;
        system("cls");
    }

    void removefila() {
        if(contador == 0) {
            printf("  |-----------------------|\n");
            printf("  |       FILA VAZIA      |\n");
            return;
        }
        if(inicio == TAM-1)
            inicio = 0;
        else inicio = inicio + 1;
        contador--;
        if(contador == 0) {
            printf("  |-----------------------|\n");
            printf("  |       FILA VAZIA      |\n");
            return;
        }
    }

    void imprimefila() {
        int i, j;
        printf("  |-----------------------|\n");
        printf("  |    FILA    | POSIÇÕES |\n");
        printf("  |-----------------------|\n");
       /* if(contador == 0) {
            printf("\n\nFila vazia\n\n");
            return;
        } */
        j=inicio;
        for(i=0; i<contador; i++){
            printf("  | %10i |    %2i    |\n", fila[j], i+1);
            printf("  |-----------------------|\n");
            if(j == TAM-1)
                j=0;
            else j=j+1;
        }
        cout << "\n";
    }

    void menu () {
	    setlocale(LC_ALL, "portuguese");
	    char esc;
	    printf("  ---------------------------------------\n");
	    printf("  -  1  |  Para inserir na fila         -\n");
        printf("  ---------------------------------------\n");
   	    printf("  -  2  |  Para remover da fila         -\n");
	    printf("  ---------------------------------------\n");
	    printf("  -  0  |  Para sair                    -\n");
   	    printf("  ---------------------------------------\n");
   	    printf("  -  Valor: ");
        esc = getch();
	    fflush(stdin);
	    //system("clear");
	    switch (esc) {
	    case '1':
	        inserefila();
	        break;
	    case '2':
	        removefila();
	        break;
        case '0':
            return;
            break;
	    default:
	        printf("VALOR INCORRETO, SEU ANIMAL.\n");
	        menu();
	    }
	    imprimefila();
	    menu();
	}
