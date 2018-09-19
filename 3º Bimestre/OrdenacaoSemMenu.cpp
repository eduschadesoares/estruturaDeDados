    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <ctime>
    #include <windows.h>

//------------------------------------------------------------------------------
// Constante global
//------------------------------------------------------------------------------

    const int TAM = 9999999;

//------------------------------------------------------------------------------
// Variáveis globais
//------------------------------------------------------------------------------

    int vetor[TAM], scratch[TAM], tamHeap = 0;

// Variáveis para armazenar o tempo gasto em cada ordenação

    float tempoTotalBubble, tempoTotalSelection, tempoTotalQuick, 
	  tempoTotalHeap, tempoTotalInsertion, tempoTotalMerge;

//------------------------------------------------------------------------------
// Protótipos das funções
//------------------------------------------------------------------------------

    void gera();
    void imprime();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    int  partitionQuick(int, int);
    void quickSort(int, int);
	void heapiFy(int);
	void buildHeap();
	void heapSort();
	void mergeSort(int, int);
	void calcTempoBubble();
	void calcTempoSelection();
	void calcTempoInsertion();
	void calcTempoQuick();
	void calcTempoHeap();
	void calcTempoMerge();

//------------------------------------------------------------------------------

    using namespace std;

//------------------------------------------------------------------------------
// Funções do programa
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Função para gerar um vetor embaralhado
//------------------------------------------------------------------------------

    void gera() {
        for(int i=0; i<TAM; i++) {
            vetor[i] = rand();
        }
    }

//------------------------------------------------------------------------------
// Função para imprimir o vetor
//------------------------------------------------------------------------------

    void imprime() {
        for(int i=0; i < TAM; i++)
            cout << "  " << vetor[i] << endl;
        cout << "  ------------  " << endl;
    }

//------------------------------------------------------------------------------
// Função Bubble Sort
//------------------------------------------------------------------------------

    void bubbleSort() {
        int pass = 1, aux = 0;
        bool sorted = false;
        while(!sorted && pass < TAM) {
            sorted = true;
            for(int i = 0; i < TAM - pass; i++)
                if(vetor[i] > vetor [i+1]) {
                    aux = vetor[i];
                    vetor[i] = vetor[i+1];
                    vetor[i+1] = aux;
                    sorted = false;
                }
            pass++;
        }
    }

//------------------------------------------------------------------------------
// Função Selection Sort
//------------------------------------------------------------------------------

    void selectionSort() {
    	int k, aux;
    	int current = 0;

    	for(int i = 0; i <=TAM-2; i++) {
    		current =i;
    		for(int k = 0; k < TAM-2; k++) {
    			if(vetor[current] > vetor [k]) {
    				current = k;
				}
			}
    		aux = vetor[i];
    		vetor[i] = vetor[current];
    		vetor[current] = aux;
		}
	}

//------------------------------------------------------------------------------
// Função Insertion Sort
//------------------------------------------------------------------------------

	void insertionSort(){
        int x, i, aux;
        bool found;
        for(int k=1; k<=TAM-1; k++){
            x = vetor[k];
            i = k-1;
            found=false;
            while(!found && i>= 0){
                if(vetor[i] > x){
                    aux = vetor[i+1];
                    vetor[i+1] = vetor[i];
                    vetor[i] = aux;
                    i--;
                } else found = true;
            }
        }
    }

//------------------------------------------------------------------------------
// Função Heap Sort
//------------------------------------------------------------------------------

	void heapiFy(int i){
		int max, aux;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if(l < tamHeap && vetor[l] > vetor[i]) max = l;
			else max = i;
		if(r < tamHeap && vetor[r] > vetor[max]) max = r;
		if(max!=i){
			aux = vetor[i];
			vetor[i] = vetor[max];
			vetor[max] = aux;
			heapiFy(max);
		}
	}

	void buildHeap() {
		tamHeap = TAM;
		for(int i = (TAM/2) - 1; i >= 0; i--) {
			heapiFy(i);
		}
	}

	void heapSort() {
		int aux;
		buildHeap();
		for(int k = TAM-1; k >= 1; k--) {
			aux = vetor[0];
			vetor[0] = vetor [k];
			vetor[k] = aux;
			tamHeap--;
			heapiFy(0);
		}
	}

//------------------------------------------------------------------------------
// Função Merge Sort
//------------------------------------------------------------------------------

    void mergeSort(int lo, int hi){
        int mid, l, h, k;
        if(lo < hi){
                mid = (lo + hi)/2;
                mergeSort(lo, mid);
                mergeSort(mid+1, hi);
                l = lo;
                h = mid+1;
                for(k=lo; k<=hi; k++){
                    if(l<=mid && (h > hi || vetor[l] < vetor[h])){
                        scratch[k] = vetor[l];
                        l++;
                    } else {
                        scratch[k] = vetor[h];
                        h++;
                    }
                }
                for(k=lo; k<=hi; k++){
                    vetor[k] = scratch[k];
                }
        }
    }

//------------------------------------------------------------------------------
// Função Quick Sort
//------------------------------------------------------------------------------

    int partitionQuick(int p, int r){
        int piv, aux = 0;
        int i, j;

        piv = vetor[p];
        i = (p - 1);
        j = (r + 1);
        while(true){
            do {
                j--;
            } while(vetor[j] > piv);
            do {
                i++;
            } while(vetor[i] < piv);

            if (i < j) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            } else return j;
        }
    }

    void quickSort(int p, int r){
        int q = 0;
        if(p < r){
            q = partitionQuick(p, r);
            quickSort(p, q);
            quickSort((q+1), r);
        }
    }

//------------------------------------------------------------------------------
// Funções para chamar e calcular tempo das funções de ordenação
//------------------------------------------------------------------------------
// BubbleSort
//------------------------------------------------------------------------------
    void calcTempoBubble(){
        gera(); // Gera um novo vetor aleatório
        clock_t time1, time2;
        time1 = clock();
        bubbleSort();
        time2 = clock() - time1;
        tempoTotalBubble = (float)time2/CLOCKS_PER_SEC;
    }

//------------------------------------------------------------------------------
// Selection Sort
//------------------------------------------------------------------------------

    void calcTempoSelection(){
        gera(); // Gera um novo vetor aleatório
        clock_t time1, time2;
        time1 = clock();
        selectionSort();
        time2 = clock() - time1;
        tempoTotalSelection = (float)time2/CLOCKS_PER_SEC;
    }

//------------------------------------------------------------------------------
// Insertion Sort
//------------------------------------------------------------------------------

    void calcTempoInsertion(){
        gera(); // Gera um novo vetor aleatório
        clock_t time1, time2;
        time1 = clock();
        insertionSort();
        time2 = clock() - time1;
        tempoTotalInsertion = (float)time2/CLOCKS_PER_SEC;
    }

//------------------------------------------------------------------------------
// Heap Sort
//------------------------------------------------------------------------------

    void calcTempoHeap(){
        gera(); // Gera um novo vetor aleatório
        clock_t time1, time2;
        time1 = clock();
        heapSort();
        time2 = clock() - time1;
        tempoTotalHeap = (float)time2/CLOCKS_PER_SEC;
    }

//------------------------------------------------------------------------------
// Merge Sort
//------------------------------------------------------------------------------

    void calcTempoMerge(){
        gera(); // Gera um novo vetor aleatório
        clock_t time1, time2;
        time1 = clock();
        mergeSort(0, TAM-1);
        time2 = clock() - time1;
        tempoTotalMerge = (float)time2/CLOCKS_PER_SEC;
    }

//------------------------------------------------------------------------------
// Quick Sort
//------------------------------------------------------------------------------

    void calcTempoQuick(){
        gera(); // Gera um novo vetor aleatório
        clock_t time1, time2;
        time1 = clock();
        quickSort(0, TAM-1);
        time2 = clock() - time1;
        tempoTotalQuick = (float)time2/CLOCKS_PER_SEC;
    }

//------------------------------------------------------------------------------
// Função Principal do Programa
//------------------------------------------------------------------------------

    int main() {

    	cout << "  Ordenando..." << endl;
        calcTempoBubble();
       	cout << "  Bubble: " << tempoTotalBubble << endl;
        calcTempoSelection();
        cout << "  Selection: " << tempoTotalSelection << endl;
        calcTempoInsertion();
        cout << "  Insertion: " << tempoTotalInsertion << endl;
        calcTempoHeap();
        cout << "  Heap: " << tempoTotalHeap << endl;
        calcTempoMerge();
        cout << "  Merge: " << tempoTotalMerge << endl;
        calcTempoQuick();
        cout << "  Quick: " << tempoTotalQuick << endl;

    }
