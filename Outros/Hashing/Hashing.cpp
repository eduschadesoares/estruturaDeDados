
//--------------------------------------------------------
//--------------------------------------------------------
//              All rights to @gomesmat                  -
// Taken from https://github.com/gomesmat/2017-Estrutura -
//--------------------------------------------------------
//--------------------------------------------------------

#include <iostream>
using namespace std;

#define TAM 10

int vetor[TAM], pos;

void inicializa()
{
    for(pos = 0; pos < TAM; pos++)
    {
        vetor[pos] = -1;
    }
}

int espalha(int chave)
{
    return chave%TAM;
}

int reespalha(int pos)
{
    return (pos + 1)%TAM;
}

void insere(int chave)
{
    int pos, cont;
    cont = 0;
    pos = espalha(chave);
    if(vetor[pos] == -1)
    {
        vetor[pos] = chave;
        cout << "Inseriu" << endl;
        return;
    }
    else
    {
        pos = reespalha(pos);
        while(vetor[pos] != -1  && cont < TAM)
        {
            pos = reespalha(pos);
            cont = cont + 1;
            cout << "Reespalha" << endl;
        }
        if(cont >= TAM)
        {
            cout << "Voce nao pode mais inserir nenhum elemento" << endl;
        }
        else
        {
            vetor[pos] = chave;
            cout << "Inseriu" << endl;
            return;
        }
    }
}

void busca(int chave)
{

    int pos = espalha(chave);
    int cont = 0;
    while(vetor[pos] != -1  && cont < TAM && vetor[pos] != chave)
    {
        pos = reespalha(pos);
        cont = cont + 1;
        cout << "Reespalha" << endl;
    }
    if(vetor[pos] == chave)
    {
        cout << "O elemento foi encontrado!" << endl;
        cout << pos << endl;

        while(vetor[pos] != -1  && cont < TAM && vetor[pos] != chave)
        {
            pos = reespalha(pos);
            cont = cont + 1;
            cout << "Reespalha" << endl;
        }
        if(vetor[pos] == chave)
        {
            cout << "O elemento foi encontrado mais uma vez!" << endl;
            cout << pos << endl;
        }
        else
        {
            cout << "O elemento nao foi encontrado!" << endl;

        }
    }
    else
    {
        cout << "O elemento nao foi encontrado!" << endl;

    }
}

void imprime()
{
    for(pos = 0; pos < TAM; pos++)
    {
        cout << vetor[pos] << endl;
    }
}

int main()
{
    inicializa();
    insere(252);
    insere(252);
    insere(1522);
    cout << endl;
    imprime();
    cout << endl;
    busca(10);
    busca(252);
    return 0;
}
