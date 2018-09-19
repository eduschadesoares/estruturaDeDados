    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctime>
    #include <clocale>
    #include <ctime>
    #include <conio.h> //Para a utilização da função getche()

    //Constantes globais
    const int TAM = 10;

    //Variáveis globais
    int lista[TAM];
    int tamanho = 0;

    using namespace std;

    //Procedimentos principais
    void insereLista();
    void removeLista();
    void buscaLista();
    void recuperaLista();
    void preencheLista();
    void menu();
    void imprime();

    //Menus para inserção ou remoção
    void menuInsereLista();
    void menuRemoveLista();
    void menuBuscaLista();
    void menuRecuperaLista();

    //Verificação para inserção ou remoção
    bool verificaCheio();
    bool verificaVazia();

    int main () {
        setlocale(LC_ALL,"");
		cout << "  Lista linear com vetor" << endl;
        cout << "  O vetor está definido em " << TAM << " posições" << endl;
        menu();
        return 0;
    }

    void insereLista(int valor) {
        int i;

        //Verifica se a lista está cheia. Já feito na função verificaCheio();
        /*  if(tamanho == TAM) {
            cout << "  Número não pôde ser inserido na lista. Lista Cheia!\n";
            return;
        } */

        for(i = tamanho; i > 0 && valor < lista[i-1]; i--) {
            lista[i] = lista [i-1];
        }

        lista[i] = valor;
        tamanho++;
        cout << "  Número " << valor << " inserido com sucesso!\n";
    }

    void removeLista(int posicao) {
        //Verifica se a lista está vazia. Já feito na função verificaVazia();
        /*if(tamanho <= 0) {
            printf("  Lista Vazia!\n");
            return;
        } */

        if(posicao <= 0 || posicao > tamanho) {
            cout << "  Posição inválida!\n";
            return;
        }

        for(int i = posicao; i < tamanho; i++) {
            lista[i-1]=lista[i];
        }
        tamanho--;

        for(int i = tamanho; i <= TAM-1; i++) {
            lista[i] = 0;
        }
        cout << "  Número removido com sucesso!\n";
    }

    void buscaLista(int valor) {
        int posicao, qntd = 0;

        for(int i = 0; i < TAM; i ++){
            if(lista[i] == valor){
                posicao = i;
                qntd++;
                cout << "  O número " << valor << " foi encontrado na posição: " << posicao+1 << "\n";
            }
        }

        if(qntd == 0)
            cout << "  O número não foi encontrado na lista! =/\n";
        else if (qntd == 1)
                cout << "  O número " << valor << " foi encontrado " << qntd << " vez.\n";
            else
                cout << "  O número " << valor << " foi encontrado " << qntd << " vezes.\n";
    }

    void recuperaLista(int posicao) {
        int valor;
        //Verifica se a lista está vazia. Já feito na função verificaVazia();
        /*if(tamanho <= 0) {
            printf("  Lista Vazia!\n");
            return;
        } */

        if(posicao <= 0 || posicao > tamanho) {
            cout << "  Posição inválida!\n";
            return;
        }

        valor = lista[posicao-1];

        cout << "  O valor encontrado na posição " << posicao << " é: " << valor << "\n";

    }

    void preencheLista() {
        srand(time(NULL));
        for(int i = 0; i < TAM; i++) {

            lista[i] = rand() % 15-0;
        }
        tamanho = TAM;
        cout << "  A lista foi automaticamente preenchida!\n";
    }

    void imprime() {
        printf("  -------------------\n");
        printf("  | P. |  VALORES   |\n");

        for(int i=TAM-1; i>=0; i--) {
            printf("  -------------------\n");
            printf("  | %2i | %10i |\n", i+1, lista[i]);
        }

        printf("  -------------------\n");
        cout << "  Impressão feita com sucesso!\n";
        cout << "  Pressione qualquer tecla para continuar";

        //Espera o usuário digitar uma tecla e a armazena numa variavel qualquer
        char lixo;
        lixo = getche();
        fflush(stdin);
        system("cls");
    }

    void menuInsereLista() {
        int valor;

        //Verifica se a lista está cheia
        if(verificaCheio()) {
            cout << "  Esse número não pôde ser inserido na lista. Lista Cheia!\n";
            return;
        }

        cout << "  Insira um valor para inserir na lista: ";
        cin >> valor;
        fflush(stdin);
        insereLista(valor);
    }

    void menuRemoveLista() {
        int posicao;

        //Verifica se a lista está vazia
        if(verificaVazia()) {
            cout << "  Não é possível remover. Lista vazia!\n";
            return;
        }

        cout << "  Insira uma posição: ";
        cin >> posicao;
        fflush(stdin);
        removeLista(posicao);
    }

    void menuBuscaLista() {
        int valor;

        //Verifica se a lista está vazia
        if(verificaVazia()) {
            cout << "  Não é possível buscar um número na lista, a lista está vazia!\n";
            return;
        }
        cout << "  Insira um valor para buscar na lista: ";
        cin >> valor;
        fflush(stdin);
        system("cls");
        buscaLista(valor);
    }

    void menuRecuperaLista() {
        int posicao;

        //Verifica se a lista está vazia (Primeira verificação)
        if(verificaVazia()) {
            cout << "  Não é possível buscar por nenhuma posição, a lista está vazia!\n";
            return;
        }

        cout << "  Insira uma posição: ";
        cin >> posicao;
        fflush(stdin);
        recuperaLista(posicao);
    }

    bool verificaCheio() {
        if(tamanho == TAM)
            return true;
        else
            return false;
    }

    bool verificaVazia() {
        if(tamanho <= 0)
            return true;
        else
            return false;
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
