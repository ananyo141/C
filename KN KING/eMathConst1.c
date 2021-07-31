// Find the value of the mathematical constant e expressed as infinite series:
// e = 1 + 1/1! + 1/2! + 1/3! +...+ 1/n!

#include <stdio.h>

int main(){
    int n, count = 1;
    double seriesSum = 1;
    printf("Enter the limit of series: ");
    scanf("%d", &n);
    while (count <= n) {
        float factorialOf = count;
        float factWith = count - 1;
        while(factWith > 1){
            factorialOf *= factWith;
            factWith--;
        }
        seriesSum += 1.0f/(factorialOf);
        count++;
    }
    printf("The series sum is %f\n",seriesSum);

    return 0;
}