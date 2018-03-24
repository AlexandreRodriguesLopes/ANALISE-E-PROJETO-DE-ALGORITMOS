#include<iostream>                          //  ALUNO: ALEXANDRE RODRIGUES LOPES FILHO
#include <cstdio>                           //  MATRICULA: 11321929
using namespace std;
int getMax(int vet[], int n)                // Uma função de utilidade para obter o valor máximo em vet[]
{


    int mx = vet[0];
    for (int i = 1; i < n; i++)
        if (vet[i] > mx)
            mx = vet[i];
    return mx;
}
void countSort(int vet[], int n, int exp)   // Uma função para fazer a contagem do tipo vet[] de acordo com
{                                           // o dígito representado por exp.

    int output[n];                          // saida vet
    int i, count[10] = {0};
    for (i = 0; i < n; i++)                 // Armazena contagem de ocorrências em count []
        count[ (vet[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)                // Alterar contagem [i] para que a contagem [i] agora contenha dados reais
        count[i] += count[i - 1];           // posição deste dígito na saída []
    for (i = n - 1; i >= 0; i--)            // Controi o vet de saida
    {
        output[count[ (vet[i]/exp)%10 ] - 1] = vet[i];
        count[ (vet[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)                 // Copie o array de saída para vet [], de modo que vet [] agora
        vet[i] = output[i];                 // contém números classificados de acordo com o dígito atual}
}
void radixsort(int vet[], int n)            // A função principal para esse tipo vet[] de tamanho n usando
{

    int m = getMax(vet, n);                 // Encontre o número máximo para saber o número de dígitos

    for (int exp = 1; m/exp > 0; exp *= 10) // Faça a contagem para cada dígito. Observe que, em vez de passar
        countSort(vet, n, exp);             // o número do dígito, exp é passado. exp é 10 ^ i
}                                           // onde i é o número do dígito atual
void print_vetor(int vet[], int n)
{
    for (int i = 0; i < n; i++)
        cout << vet[i] << " ";
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
    radixsort(vet, n);
    printf("Ordenada por radix sort: \n");
    print_vetor(vet, n);
    return 0;
}
