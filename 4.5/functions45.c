#include <stdio.h>
#include <stdlib.h>
#include "45.h"

void VvodVector(int **x, int nx, FILE*fin){
    *x=(int*)malloc(nx * sizeof(int));
    for (int i=0; i < nx; i++) {
        fscanf(fin, "%i", &(*x)[i]);
    }
}

void VivodVector(int *x, int nx, FILE *fout){
    for (int i=0; i < nx; i++) {
        fprintf(fout, "%i ", x[i]);
    }
}

void Kratno5(int *fl, int nx, int *x){
    *fl=1;
    int i = 0;
    while (i < nx && *fl == 1) {
        if (x[i] % 5 != 0) {
            *fl = 0;
        }
        i++;
    }
}

void IndexMax(int *imax, int nx, int *x) {
    *imax = 0;
    for (int i=1; i < nx; i++) {
            if (x[i]> x[*imax]) {
                *imax = i;
            }
    }
}

void IndexMin(int *imin, int nx, int *x) {
    *imin = 0;
    for (int i=1; i < nx; i++) {
            if (x[i] < x[*imin]) {
                *imin = i;
            }
    }
}

void FreeVector(int **x) {
    free(*x);
}
