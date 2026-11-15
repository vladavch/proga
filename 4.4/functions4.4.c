#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "44.h"

 void VvodVector(float **x, int nx, FILE *fin) {
    *x = (float*)malloc(nx * sizeof(float));
    for (int i = 0; i < nx; i++) {
            fscanf(fin, "%f", &(*x)[i]);
        }
    }

void VivodVector(float *x, int nx, FILE *fout){
    for (int i = 0; i < nx; i++) {
            fprintf(fout, "%.2f ", x[i]);
        }
        fprintf(fout, "\n");
    }



void MaxCount(int *count, int nx, float *x, float k) {
    *count = 0;
    for (int i = 0; i < nx; i++) {
        if (fabs(x[i]) > k ) {
            (*count)++;
        }
    }
}

void FreeVector(float **x){
    free(*x);
}
