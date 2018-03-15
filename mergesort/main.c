/* ALUNO: ALEXANDRE RODRIGUES LOPES FILHO
   MATRIULA: 11321929                    */

#include<stdlib.h>
#include<stdio.h>

void merge(int vet[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = vet[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vet[k] = L[i];
            i++;
        }
        else
        {
            vet[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vet[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vet[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int vet[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(vet, l, m);
        mergeSort(vet, m+1, r);

        merge(vet, l, m, r);
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

    mergeSort(vet, 0, n - 1);

    printf("\nOrdenada por mergesort \n");
    print_vetor(vet, n);
    return 0;
}
