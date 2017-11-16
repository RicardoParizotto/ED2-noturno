#include<stdio.h>
#include<stdlib.h>

#define MAX 1024
#define MENOS_INFINITO (-1000000000)

#define LEFT(x) (x << 1)
#define RIGHT(x) (LEFT(x) + 1)
#define PAI(x) (x >> 1)

typedef struct heap {
  size_t size;      //quantidade de itens armazenados
  size_t length;	//tamanho máximo da heap
  int A[MAX];		//array de chaves
} heap;

void heapify( heap * H, int i ){
	int max = i, aux;

	if(LEFT(i) <= H->size)
		if(H->A[LEFT(i)] > H->A[i]) max = LEFT(i);
	if(RIGHT(i) <= H->size)
		if(H->A[RIGHT(i)] > H->A[max]) max = RIGHT(i);
	if(i != max){
		aux = H->A[i]; H->A[i] = H->A[max]; H->A[i] = aux;
		heapify(H, max);
	}
};

void build_heap( heap * H, int N){
	int aux, i;

	if(N <= 1){
		printf("ERRROU");
		exit(1);
	}

	H->size = N;
	H->length = MAX - 1;

	for ( i = N/2; i > 0; i-- )
		heapify(H, i);	
}

//aumenta a prioridade da chave do indice i para o valor de rebeca
void increase_key( heap * H, int i, int rebeca ){
	int aux;	

	if(rebeca <= H->A[i]){
		printf("ERROU!");
		exit(1);
	}
	
	H->A[i] = rebeca;

	while( i > 1 && H->A[PAI(i)] <  H->A[i]){
		aux = H->A[i]; H->A[i] = H->A[PAI(i)]; H->A[PAI(i)] = aux;
		i = PAI(i);
	}
}

void insert_key( heap * H, int chave ){

	if(H->size == H->length){
		printf("Errou! Não cabeu mais nada!");
		exit(1);
	}

	H->size++;
	H->A[H->size] = MENOS_INFINITO;
	
	increase_key(H, H->size, chave);
	
}

//retorna o máximo e remove ele da heap
int extract_max(heap * H){
	int aux = H->A[1];

	if(H->size < 1){
		printf("errou!");
		exit(1);
	}
	
	H->A[1] = H->A[H->size--];	
	
	heapify(H, 1);
	return aux;
	
}

int main ( void ){
	//seu código aqui

	return 0;
}
















