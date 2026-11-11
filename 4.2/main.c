#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "lab42.h"

int main() {
    float **A;
    float *B;
    int n;
    FILE *fin, *fout;

    setlocale(LC_ALL,"Russian");

    do{
        printf("Количество строк и столбцов n: ");
        scanf("%i", &n);
    }while (n<=0 || n>4);

    fin = fopen("finA.txt", "r");
    VvodMatrix(fin, &A, n);
    fclose(fin);

    B2(A, &B, n);

    fout = fopen("fout.txt", "w");
    VivodMassiv(B, n, fout);
    fclose(fout);

    FreeMatrix(A, n);
    FreeMassiv(B);
}
