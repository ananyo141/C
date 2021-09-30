#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H 1

#define ARRSIZE 50
#define ArrLen(arrname)   (sizeof(arrname) / sizeof(arrname[0]))
#define DEBUG(elem,type)  printf(#elem " = " type "\n", elem)

void printArray(double arr[], int len);
void readArray (double arr[], int len);
int  freeRead  (double arr[], int maxlen);
void printMatrix(int m, int n, double arr[m][n]);
void readMatrix (int m, int n, double arr[m][n]);

#endif
