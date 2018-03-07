/*  ALUNO: ALEXANDRE RODRIGUES LOPES FILHO
    MATRICULA: 11321929                     */

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) //função de troca
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void selection_sort(int vet[], int n) //função para ordenar
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (vet[j] < vet[min])
            min = j;

        swap(&vet[min], &vet[i]);

    }
}

void print_vetor(int vet[], int size) //função print na tela
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", vet[i]);
    printf("\n");
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

    selection_sort(vet, n);

    printf("Ordenada por selection sort: \n");
    print_vetor(vet, n);

    return 0;
}
