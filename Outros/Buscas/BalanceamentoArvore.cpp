
//--------------------------------------------------------
//--------------------------------------------------------
//              All rights to @gomesmat                  -
// Taken from https://github.com/gomesmat/2017-Estrutura -
//--------------------------------------------------------
//--------------------------------------------------------

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tam 20000

int vetor[tam];
double contadorBin = 0;
double contadorSeq = 0;
double contadorArv = 0;
double contadorArvAvl = 0;

struct no {
            int dado;
            struct no *esq;
            struct no *dir;
            int bal;
			};

struct no* raiz, *raiz_avl;

struct no *cria_no(int valor){
    struct no *aux = new (struct no);
    aux->dado=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->bal=0;
    return aux;
};

// Rotação para a esquerda
void esquerda(struct no *p) {

	struct no *q, *hold;

   q = p->dir;
   hold = q->esq;
   q->esq = p;
   p->dir = hold;
}

//Rotação para a direita
void direita(struct no *p) {

	struct no *q, *hold;

   q = p->esq;
   hold = q->dir;
   q->dir = p;
   p->esq = hold;
}

void insere_bal(int chave)
{

	struct no *pp=NULL, *p=raiz_avl, *pajovem=NULL, *ajovem=raiz_avl, *q, *filho;
   int imbal;

   if (p==NULL) {             /* Arvore vazia */
   	  raiz_avl = cria_no(chave);  /* Funcao para criacao de um novo no */
      return;
   }

/* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
   while (p!=NULL) {
   	if (chave < p->dado)
      	q = p->esq;
         else q = p->dir;
      if (q!=NULL)
      	if (q->bal != 0) {
         	pajovem=p;
            ajovem=q;
      }
      pp = p;
      p = q;
   }

   q = cria_no(chave);

   if (chave<pp->dado)
   	pp->esq=q;
      else pp->dir=q;

/* Balanceamento de todos os nós entre a jovem e q devem ser ajustados */
   if (chave<ajovem->dado)
   	filho = ajovem->esq;
      else filho = ajovem->dir;

   p = filho;

   while (p!=q) {
   	if (chave < p->dado) {
      	p->bal=1;
         p=p->esq;
   	} else {
   			p->bal = -1;
            p=p->dir;
   			}
   }

   if (chave<ajovem->dado)
   	imbal = 1;
      else imbal = -1;

   if (ajovem->bal==0) {      /*Não houve desbalanceamento */
   	ajovem->bal=imbal;
      return;
   }


	if (ajovem->bal!=imbal) {   /*Não houve desbalanceamento */
   	ajovem->bal=0;
      return;
   }

	/* Houve desbalanceamento */
   if (filho->bal == imbal) {
   	p=filho;
      if (imbal==1)        /* Faz rotação simples */
      	direita(ajovem);
      	else esquerda(ajovem);
      ajovem->bal=0;
      filho->bal=0;
   } else {
   		if (imbal==1) {	  /*Faz rotação dupla */
      		p=filho->dir;
         	esquerda(filho);
         	ajovem->esq=p;
         	direita(ajovem);
      	} else {
              p=filho->esq;
              direita(filho);
              ajovem->dir=p;
              esquerda(ajovem);
         }
         if (p->bal==0) {
         	ajovem->bal=0;
            filho->bal=0;
         } else {
         		if (p->bal == imbal) {
               	ajovem->bal = - imbal;
                  filho->bal = 0;
               } else {
               	ajovem->bal = 0;
                  filho->bal = imbal;
               }
         }
      p->bal=0;
   }

   if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
      raiz_avl = p;
      else if (ajovem==pajovem->dir)
      			 pajovem->dir = p;
                else pajovem->esq = p;

   return;
}

//Insere valor em uma árvore binária
void insere(int valor)
{

   struct no *atual, *aux;

   aux = new(struct no);
   aux->dado = valor;
   aux->esq = NULL;
   aux->dir = NULL;

   atual=raiz;

   if (atual==NULL) {
   	  raiz = aux;
   	  return;
   }

   while (1) {
         	if (valor < atual->dado)
            	if (atual->esq==NULL) {
            	    atual->esq=aux;
            	    return;
                 }
                 else atual=atual->esq;
            else if (atual->dir==NULL) {
            	    atual->dir=aux;
            	    return;
                 }
                 else atual=atual->dir;
         }
}




// Cira um no e preenche os membros


void em_ordem(struct no *atual)
{
	if (atual!=NULL) {
   	   em_ordem(atual->esq);
       printf("%d ",atual->dado);
       em_ordem(atual->dir);
	}
}

void gera(){
	int i;
	srand (time(NULL));
	for(i=0; i<tam; i++) vetor[i] = rand();
}

void imprime(){
	for(int i=0; i<tam; i++){
		printf("[%d]\n", vetor[i], i+1, tam);
	}
}

void selectionSort(){
	int aux;
	int current = 0;

	for(int i=0; i <= tam-2; i++){
		current = i;
		for(int k = i+1; k <= tam-1; k++){
			if (vetor[current] > vetor[k]) current = k;
		}
		aux = vetor[i];
		vetor[i] = vetor[current];
		vetor[current] = aux;
	}
}

void buscaArv(int valor){
    struct no *atual;
    atual = raiz;
    while (atual != NULL){
        contadorArv++;
        if(valor == atual -> dado){
//            printf("Achei!");
            return;
        }
        if(valor < atual->dado) atual = atual -> esq;
        else atual = atual -> dir;
    }
//    printf("Não achei!");
}

void buscaArvAvl(int valor){
    struct no *atual;
    atual = raiz;
    while (atual != NULL){
        contadorArvAvl++;
        if(valor == atual -> dado){
//            printf("Achei!");
            return;
        }
        if(valor < atual->dado) atual = atual -> esq;
        else atual = atual -> dir;
    }
//    printf("Não achei!");
}

void buscaSeq (int valor){
    int i=0;
    while (i < tam && valor >= vetor[i]){
        if (valor == vetor[i]){
//            printf("Achei!");
            return;
        }
        i++;
        contadorSeq++;
    }
//    printf("Não achei!");
}

void buscaBin (int valor){
    int inicio = 0;
    int fim = tam-1;
    int meio;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        contadorBin++;
        if (valor == vetor[meio]) {
                printf("Achei!\n");
                return;
        }
        if (valor < vetor[meio]) fim = meio-1;
        else /* valor > vetor[meio] */ inicio = meio+1;
    }
    printf("N�o achei!\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    gera();
    for (int i=0; i<tam; i++){
        insere(vetor[i]);
        insere_bal(vetor[i]);
    }
    selectionSort();

    int busca;
    for (int i=1; i<=1000; i++){
        busca = rand();
        buscaBin(busca);
        buscaSeq(busca);
        buscaArv(busca);
        buscaArvAvl(busca);
    }

    printf("\n");
    printf(" M�dia de Buscas Sequencial: %.2f\n", contadorSeq/1000);
    printf(" M�dia de Buscas Bin�rias: %.2f\n", contadorBin/1000);
    printf(" M�dia de Buscas em �rvore Bin�ria: %.2f\n", contadorArv/1000);
    printf(" M�dia de Buscas em �rvore AVL: %.2f\n", contadorArvAvl/1000);
    printf("\n");


//    imprime();
    system("pause");
    return 0;
}
