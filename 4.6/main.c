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
        printf("������� ���������� ��������� nA: ");
        scanf("%i", &nA);
    }while (nA<1 || nA>20);

    do{
        printf("������� ���������� ��������� nB: ");
        scanf("%i", &nB);
    }while (nB<1 || nB>20);

    do{
        printf("������� ���������� ��������� nC: ");
        scanf("%i", &nC);
    }while (nC<1 || nC>20);

    float l, h;
    printf("������� ������ ������� ���������: ");
    scanf("%f", &l);
    do {
        printf("������� ������� ������� ���������: ");
        scanf("%f", &h);
    } while (h < l);

    float *A, *B, *C;
    VvodVector(&A, nA, finA);
    VvodVector(&B, nB, finB);
    VvodVector(&C, nC, finC);

    fclose(finA);
    fclose(finB);
    fclose(finC);

    fprintf(fout, "��������: [%5.2f; %5.2f]\n", l, h);

    int *nomA, *nomB, *nomC;
    int kA, kB, kC;

    VneDiapazona(A, nA, l, h, &nomA, &kA);
    VneDiapazona(B, nB, l, h, &nomB, &kB);
    VneDiapazona(C, nC, l, h, &nomC, &kC);

    fprintf(fout, "������ ������ A\n");
    VivodVector(A, nA, fout);
        if (kA == 0) {
        fprintf(fout, "��� �������� ������� A �������� � �������� [%5.2f; %5.2f], ����� ������ ����\n\n", l, h);
    } else {
        fprintf(fout, "������ ��������� ������� A ��� ��������� [%5.2f; %5.2f] (����� %i):\n", l, h, kA);
        VivodNomera(nomA, kA, fout);
        fprintf(fout, "\n");
    }

    fprintf(fout, "������ ������ B\n");
    VivodVector(B, nB, fout);
        if (kB == 0) {
        fprintf(fout, "��� �������� ������� B �������� � �������� [%5.2f; %5.2f], ����� ������ ����\n\n", l, h);
    } else {
        fprintf(fout, "������ ��������� ������� B ��� ��������� [%5.2f; %5.2f] (����� %i):\n", l, h, kB);
        VivodNomera(nomB, kB, fout);
        fprintf(fout, "\n");
    }

    fprintf(fout, "������ ������ C\n");
    VivodVector(C, nC, fout);
    if (kC == 0) {
        fprintf(fout, "��� �������� ������� C �������� � �������� [%5.2f; %5.2f], ����� ������ ����\n\n", l, h);
    } else {
        fprintf(fout, "������ ��������� ������� C ��� ��������� [%5.2f; %5.2f] (����� %i):\n", l, h, kC);
        VivodNomera(nomC, kC, fout);
        fprintf(fout, "\n");
    }

    FreeVectorF(&A);
    FreeVectorF(&B);
    FreeVectorF(&C);
    FreeVectorI(&nomA);
    FreeVectorI(&nomB);
    FreeVectorI(&nomC);
    fclose(fout);
}
