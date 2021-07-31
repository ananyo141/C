// WAP to ask the user to enter the numbers from 1 to 16 in any order and then display the numbers in a 4 
// by 4 arrangement, followed by the sums of the rows, columns and diagonals.
#include <stdio.h>
#define INT_LIMIT 16

// Use this for the magic square //
// 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1 //

void rowSums(int arr[INT_LIMIT]){
    printf("Row Sums: ");
    {int j=0,total=0;
    while (j<INT_LIMIT){
        total+=arr[j];
        if(j%4==3){
            printf("%d ",total);
            total=0;
        }
        j++;
    }}}

void columnSums(int arr[INT_LIMIT]){
    printf("Column Sums: ");
    {int i=0,j=0;
    while (i<4){
        int total=0;
        j=i;
        while(j<INT_LIMIT){
            total+=arr[j];
            j+=4;            
        }
        printf("%d ", total);
        i++;
    }}}

void diagonalSums(int arr[INT_LIMIT]) {
    printf("Diagonal Sums: ");
    {int i=0,total=0;
    while(i<INT_LIMIT){
        total+=arr[i];
        i+=5;
    }
    printf("%d ",total);
    }
    {
    int j=3,total=0;
    while(j<INT_LIMIT-1){
        total+=arr[j];
        j+=3;
    }
    printf("%d ",total);
    }
     
}

int main()
{
    int numArr[INT_LIMIT];
    printf("Enter the numbers from 1 to 16 in any order: ");
    {int i=0;
    while(i<INT_LIMIT){
        scanf("%d",&numArr[i]);
        i++;
    }}
    {int i=0;
    while(i<INT_LIMIT){
        if (i%4==0){
            printf("\n");
        }
        printf("%d ",numArr[i]);
        i++;
    }}
    printf("\n");
    rowSums(numArr);
    printf("\n");
    columnSums(numArr);
    printf("\n");
    diagonalSums(numArr);
    printf("\n");

    return 0;
}