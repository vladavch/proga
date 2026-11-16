#include <stdio.h>
#include <stdlib.h>
#include "46.h"

void VvodVector(float **x, int nx, FILE *fin){
    *x = (float*)malloc(nx * sizeof(float));
    for (int i = 0; i < nx; i++) {
        fscanf(fin, "%f", &(*x)[i]);
    }
}

void VivodVector(float *x, int nx, FILE *fout){
    for (int i = 0; i < nx; i++) {
        fprintf(fout, "%5.2f ", x[i]);
    }
    fprintf(fout, "\n");
}

void VivodNomera(int *x, int nx, FILE *fout){
    for (int i = 0; i < nx; i++) {
        fprintf(fout, "%i ", x[i]);
    }
    fprintf(fout, "\n");
}

void PervyjVne(float *x, int nx, float l, float h, int **result, int *nresult){
    *nresult = 0;
    int i = 0;
    while (i < nx && *nresult == 0) {
        if (x[i] < l || x[i] > h) {
            *result = (int*)malloc(sizeof(int));
            (*result)[0] = i + 1;
            *nresult = 1;
        }
        i++;
    }
}

void DopolnitVne(float *x, int nx, float l, float h, int **result, int *nresult){
    if (*nresult > 0) {
        for (int i = (*result)[0]; i < nx; i++) {
            if (x[i] < l || x[i] > h) {
                *result = (int*)realloc(*result, (*nresult + 1) * sizeof(int));
                (*result)[*nresult] = i + 1;
                (*nresult)++;
            }
        }
    }
}

void FreeVectorF(float **x) {
    free(*x);
}

void FreeVectorI(int **x) {
    free(*x);
}
