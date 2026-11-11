#include <stdio.h>>
#include <malloc.h>
#include "lab42.h"

 void VvodMatrix(FILE *fin, float ***A, int n) {
    *A = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        (*A)[i] = (float*)malloc(n * sizeof(float));
         for (int j = 0; j < n; j++) {
            fscanf(fin, "%f", &(*A)[i][j]);
        }
    }
    return;
}

void VivodMassiv(float *B, int n, FILE *fout) {
    fprintf(fout, "B: ");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%.1f ", B[i]);
    }
    fprintf(fout, "\n");
}


int maxinrow(float *row, int n, float diagonal) {
    int result=0;
    for (int j = 0; j < n; j++) {
        if (row[j]>diagonal){
            result = 1;
        }
        j++;
    }
    return result;
}


void B2(float **A, float **B, int n) {
    *B = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        (*B)[i]=(float)maxinrow(A[i], n, A[i][i]);
        }
        return;
    }

void FreeMatrix(float **A, int n) {
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
}
void FreeMassiv(float *B){
    free(B);
}
