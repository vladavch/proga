#ifndef LAB42_H_INCLUDED
#define LAB42_H_INCLUDED
#include <stdio.h>

void VvodMatrix(FILE *fin, float ***A, int n);
void VivodMassiv(float *B, int n, FILE *fout);
int maxinrow(float *row, int n, float diagonal);
void B2(float **A, float **B, int n);
void FreeMatrix(float **A, int n);
void FreeMassiv(float *B);

#endif // LAB42_H_INCLUDED
