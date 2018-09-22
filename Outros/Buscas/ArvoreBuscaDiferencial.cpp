#include <stdio.h>

#define ORDEM 4

struct no {
    int dados[ORDEM-1];
    struct no *filhos[ORDEM];
    int n_filhos;
};
struct no *raiz = NULL;

struct no *cria_no(int chave) {
    struct no *novo;
    int i;

    novo = new (struct no);
    novo->dados[0] = chave;

    for (i=0; i<ORDEM; i++)
        novo->filhos[i] = NULL;

    novo->n_filhos = 2;
    return novo;
};

void insere_folha(struct no *atual, int chave) {

    int i;

    for (i=atual->n_filhos-1 ; i>0 && chave<atual->dados[i-1] ; i--)
        atual->dados[i]=atual->dados[i-1];
    atual->dados[i] = chave;
    atual->n_filhos++;
}

int encontra_chave(struct no *atual, int chave) {

    int i=0;

    while (i<atual->n_filhos-1 && chave>atual->dados[i])
        i++;
    return i;
}

struct no *encontra_no(int chave, int &posicao) {

    struct no *atual, *anterior;

    anterior=NULL;
    atual=raiz;
    while (atual!=NULL) {
        posicao=encontra_chave(atual,chave);
        anterior = atual;
        if (posicao<atual->n_filhos - 1 && chave==atual->dados[posicao]) {
            return atual;
        }
        atual = atual->filhos[posicao];
    }
    return anterior;
}

void insere(int chave) {
    struct no *novo, *atual;
    int posicao;

    if (raiz == NULL) {
        raiz = cria_no(chave);
        return;
    }
    atual = encontra_no(chave, posicao);

    if (atual->n_filhos < ORDEM)
        insere_folha(atual, chave);
    else {
        novo = cria_no(chave);
        atual->filhos[posicao] = novo;
    }
}

void percurso(struct no *atual) {
    int i;

    if (atual!=NULL) {

        for (i=0; i<atual->n_filhos-1; i++) {
            percurso(atual->filhos[i]);
            printf("%d ",atual->dados[i]);
        }
        percurso(atual->filhos[atual->n_filhos-1]);
    }
}

void busca(int chave) {
    struct no *atual;
    int posicao;
    atual = encontra_no(chave, posicao);
    if (atual->dados[posicao] == chave)
        printf("Achei");
    else printf("N�o achei");
}

int main() {
    insere(4);
    insere(3);
    insere(2);
    insere(1);

    percurso(raiz);

    busca(3);

    return 0;
}
