// Program procedurally evaluates user input expression from left to right, no operator takes
// precedence over other. 
#include <stdio.h>

int main() {
    float num, result;
    char operator;
    printf("Enter your expression: ");
    scanf("%f", &num);
    result = num;

    for(;;) {
        while ((operator = getchar()) == ' ');    // discards any spaces  
        if (operator == '\n')
            goto LOOPEXIT;                        // breaks out of both the switch and for loop

        scanf("%f", &num);
        switch(operator) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                result /= num;
                break;
        }
    }

    LOOPEXIT:
    printf("The result of the left-associative expression is: %.2f\n", result);

    return 0;
}