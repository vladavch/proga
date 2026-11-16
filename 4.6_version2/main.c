#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "46.h"

int main() {
    setlocale(LC_ALL,"Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *finA,*finB,*finC, *fout;

    finA = fopen("finA46.txt", "r");
    finB = fopen("finB46.txt", "r");
    finC = fopen("finC46.txt", "r");
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

    float l, h;
    printf("Введите нижнюю границу диапазона: ");
    scanf("%f", &l);
    do {
        printf("Введите верхнюю границу диапазона: ");
        scanf("%f", &h);
    } while (h < l);

    float *A, *B, *C;
    VvodVector(&A, nA, finA);
    VvodVector(&B, nB, finB);
    VvodVector(&C, nC, finC);

    fclose(finA);
    fclose(finB);
    fclose(finC);

    fprintf(fout, "Диапазон: [%5.2f; %5.2f]\n", l, h);

    int *nomA, *nomB, *nomC;
    int kA, kB, kC;

    PervyjVne(A, nA, l, h, &nomA, &kA);
    DopolnitVne(A, nA, l, h, &nomA, &kA);

    PervyjVne(B, nB, l, h, &nomB, &kB);
    DopolnitVne(B, nB, l, h, &nomB, &kB);

    PervyjVne(C, nC, l, h, &nomC, &kC);
    DopolnitVne(C, nC, l, h, &nomC, &kC);

    fprintf(fout, "Введен вектор A\n");
    VivodVector(A, nA, fout);
        if (kA == 0) {
        fprintf(fout, "Все элементы массива A попадают в диапазон [%5.2f; %5.2f], новый массив пуст\n\n", l, h);
    } else {
        fprintf(fout, "Номера элементов массива A вне диапазона [%5.2f; %5.2f] (всего %i):\n", l, h, kA);
        VivodNomera(nomA, kA, fout);
        fprintf(fout, "\n");
    }

    fprintf(fout, "Введен вектор B\n");
    VivodVector(B, nB, fout);
        if (kB == 0) {
        fprintf(fout, "Все элементы массива B попадают в диапазон [%5.2f; %5.2f], новый массив пуст\n\n", l, h);
    } else {
        fprintf(fout, "Номера элементов массива B вне диапазона [%5.2f; %5.2f] (всего %i):\n", l, h, kB);
        VivodNomera(nomB, kB, fout);
        fprintf(fout, "\n");
    }

    fprintf(fout, "Введен вектор C\n");
    VivodVector(C, nC, fout);
    if (kC == 0) {
        fprintf(fout, "Все элементы массива C попадают в диапазон [%5.2f; %5.2f], новый массив пуст\n\n", l, h);
    } else {
        fprintf(fout, "Номера элементов массива C вне диапазона [%5.2f; %5.2f] (всего %i):\n", l, h, kC);
        VivodNomera(nomC, kC, fout);
        fprintf(fout, "\n");
    }

    FreeVectorF(&A);
    FreeVectorF(&B);
    FreeVectorF(&C);
    if (kA > 0) FreeVectorI(&nomA);
    if (kB > 0) FreeVectorI(&nomB);
    if (kC > 0) FreeVectorI(&nomC);
    fclose(fout);
}
