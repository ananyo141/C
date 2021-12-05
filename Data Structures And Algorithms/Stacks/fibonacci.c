// Write recursive fibonacci series

#include <stdio.h>

// Function Prototypes //
void fibonacci    (int lim);
void fibonacciTail(int lim, int num1, int num2);

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    fibonacci(num);

    return 0;
}

// Definitions //
void fibonacci(int lim) {
    /* Wrapper for the tail recursive fibonacci
    algorithm */
    fibonacciTail(lim, -1, 1);
    putchar('\n');
}

void fibonacciTail(int lim, int num1, int num2) {
    /* Actual function performing recursion */
    int currNum = num1 + num2;
    if (currNum >= lim) return;
    printf("%d ", currNum);
    return fibonacciTail(lim, num2, currNum);
}

