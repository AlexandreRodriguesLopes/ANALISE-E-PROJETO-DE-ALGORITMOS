/*  ALUNO: ALEXANDRE RODRIGUES LOPES FILHO
    MATRICULA: 11321929                     */

#include<stdio.h>

void swap(int* x, int* y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
int partition (int vet[], int low, int high)
{
    int pivot = vet[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (vet[j] <= pivot)
        {
            i++;
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[high]);
    return (i + 1);
}
void quickSort(int vet[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(vet, low, high);

        quickSort(vet, low, pi - 1);
        quickSort(vet, pi + 1, high);
    }
}
void print_vetor(int vet[], int n)
{
    int i;
    for (i=0; i < n; i++)
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

    quickSort(vet, 0, n-1);

    printf("Ordenada por quicksort: \n");
    print_vetor(vet, n);

    return 0;
}
