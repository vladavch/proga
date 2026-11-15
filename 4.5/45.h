#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>

void VvodVector(int **x, int nx, FILE *fin);
void VivodVector(int *x, int nx, FILE *fout);
void Kratno5(int *flag, int nx, int *x);
void IndexMax(int *imax, int nx, int *x);
void IndexMin(int *imin, int nx, int *x);
void FreeVector(int **x);

#endif // FUNCTIONS_H_INCLUDED
