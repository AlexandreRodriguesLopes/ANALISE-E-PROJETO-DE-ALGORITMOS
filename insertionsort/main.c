/* ALUNO: ALEXANDRE RODRIGUES LOPES FILHO
   MATRIULA: 11321929                    */

#include <stdio.h>
#include <math.h>

void insertion_sort(int vet[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = vet[i];
       j = i-1;

       while (j >= 0 && vet[j] > key)
       {
           vet[j+1] = vet[j];
           j = j-1;
       }
       vet[j+1] = key;
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

    insertion_sort(vet, n);
    printf("Ordenada por insertion sort: \n");
    print_vetor(vet, n);
    return 0;
}
