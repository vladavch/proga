#ifndef H_44_INCLUDED
#define H_44_INCLUDED
#include <stdio.h>

void VvodVector(float **x, int nx, FILE *fin);
void VivodVector(float *x, int nx, FILE *fout);
void MaxCount(int *count, int nx, float *x, float k);
void FreeVector(float **x);

#endif // H_44_INCLUDED
