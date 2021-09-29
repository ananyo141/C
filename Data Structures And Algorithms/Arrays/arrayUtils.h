#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#define ARRSIZE 50
#define ArrLen(arrname) (sizeof(arrname) / sizeof(arrname[0]))

void printArray(double arr[], int len);
void readArray (double arr[], int len);

#endif
