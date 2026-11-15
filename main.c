#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "44.h"

int main() {
    setlocale(LC_ALL,"Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *finA,*finB,*finC, *fout;

    finA = fopen("finA44.txt", "r");
    finB = fopen("finB44.txt", "r");
    finC = fopen("finC44.txt", "r");
    fout = fopen("fout.txt", "w");

    int nA, nB, nC;

    do{
        printf("Введите количество элементов nA: ");
        scanf("%i", &nA);
    }while (nA<1 || nA>20);

    do{
        printf("Введите количество элементов nB: ");
        scanf("%i", &nB);
    }while (nB<1 || nB>20);

    do{
        printf("Введите количество элементов nC: ");
        scanf("%i", &nC);
    }while (nC<1 || nC>20);

    float k;
    do{
    printf("Введите число k: ");
    scanf("%f", &k);
    }while (k<0);

    float *A, *B, *C;
    VvodVector(&A, nA, finA);
    VvodVector(&B, nB, finB);
    VvodVector(&C, nC, finC);

    fclose(finA);
    fclose(finB);
    fclose(finC);

    fprintf(fout, "Введен вектор A\n");
    VivodVector(A, nA, fout);
    fprintf(fout, "Введен вектор B\n");
    VivodVector(B, nB, fout);
    fprintf(fout, "Введен вектор C\n");
    VivodVector(C, nC, fout);

    int countA,countB, countC;
    MaxCount(&countA, nA, A, k);
    MaxCount(&countB, nB, B, k);
    MaxCount(&countC, nC, C, k);

    fprintf(fout, "Количество элементов с |x|>k:\n");
    fprintf(fout, "A: %i\nB: %i\nC: %i\n\n", countA, countB, countC);

if (countA == 0 && countB == 0 && countC == 0) {
        fprintf(fout, "Ни в одном массиве нет таких элементов\n");
    } else if (countA > countB && countA > countC) {
        fprintf(fout, "Наибольшее количество в массиве: A\n");
    } else if (countB > countA && countB > countC) {
        fprintf(fout, "Наибольшее количество в массиве: B\n");
    } else if (countC > countA && countC > countB) {
        fprintf(fout, "Наибольшее количество в массиве: C\n");
    } else if (countA == countB && countA > countC) {
        fprintf(fout, "Наибольшее количество в массивах: A и B\n");
    } else if (countA == countC && countA > countB) {
        fprintf(fout, "Наибольшее количество в массивах: A и C\n");
    } else if (countB == countC && countB > countA) {
        fprintf(fout, "Наибольшее количество в массивах: B и C\n");
    } else {
        fprintf(fout, "Во всех массивах одинаковое количество\n");
    }


    FreeVector(&A);
    FreeVector(&B);
    FreeVector(&C);
    fclose(fout);
}
