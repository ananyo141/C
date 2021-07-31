// Find the even squares between 1 to N
#include <stdio.h>

int main(){
    int n, start = 2;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    while (start*start <= n){
        printf("%d\n", start*start);
        start += 2;
    }

    return 0;
}