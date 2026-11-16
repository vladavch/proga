#ifndef H_46_INCLUDED
#define H_46_INCLUDED
#include <stdio.h>

void VvodVector(float **x, int nx, FILE *fin);
void VivodVector(float *x, int nx, FILE *fout);
void VivodNomera(int *x, int nx, FILE *fout);
void PervyjVne(float *x, int nx, float l, float h, int **result, int *nresult);
void DopolnitVne(float *x, int nx, float l, float h, int **result, int *nresult);
void FreeVectorF(float **x);
void FreeVectorI(int **x);

#endif // FUNCTIONS_H_INCLUDED
