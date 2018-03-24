/*  ALUNO: Alexandre Rodrigues Lopes Filho
    MATRICULA: 11321929                     */

#include<stdlib.h>
#include<stdio.h>

void swap(int *x, int *y) //função de troca
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
void print_vetor(int vet[], int size) //função print na tela
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

void heapify(int vet[], int max, int i)
{
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;


    if (esq < max && vet[esq] > vet[maior])
        maior = esq;


    if (dir < max && vet[dir] > vet[maior])
        maior = dir;


    if (maior != i)
    {
        swap(&vet[i], &vet[maior]);

    heapify(vet, max, maior);
    }
}


void heapSort(int vet[], int max)
{

    for (int i = max / 2 - 1; i >= 0; i--)
        heapify(vet, max, i);


    for (int i=max-1; i>=0; i--)
    {

        swap(&vet[0], &vet[i]);


        heapify(vet, i, 0);
    }
}

int main()
{

    int vet[101];
    int n = sizeof(vet)/sizeof(vet[0]);
    int i;

	FILE *lerascii;
	lerascii = fopen("couting.txt","r");

	for(i=0; i<101; i++){
		fscanf(lerascii, "%d\n", &vet[i]);
	}

    heapSort(&vet[0],n);

    printf("Ordenada por heap sort: \n");
    print_vetor(vet, n);

	return 0;
}
