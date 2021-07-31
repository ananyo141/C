// Program continues to add terms until the current term becomes less than e,
// where e is small float entered by user.

#include <stdio.h>

int main() {
    float e;
    printf("Enter the lower limit until you want the program to continue adding terms: ");
    scanf("%f", &e);

    int count = 1;
    double seriesSum = 1;
    float value;
    do {
        float factorialOf = count;
        float factWith = count - 1;
        while (factWith > 1){
            factorialOf *= factWith;
            factWith--;
        }
        value = 1.0f / (factorialOf);
        seriesSum += value;
        count++;
    } while (value > e);
    
    printf("The series sum is %f\n", seriesSum);

    return 0;
}