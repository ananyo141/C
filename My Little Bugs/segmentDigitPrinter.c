// Print the digits entered by the user as a seven segment display.
#include <stdio.h>
#include <ctype.h>
#define DIGITS 10
#define SEGMENTS_PER_DIG 7
#define MAX_DIGITS 8

// external variables //
char digits[4][MAX_DIGITS * 4];
const int segments[DIGITS][SEGMENTS_PER_DIG] = {{1, 1, 1, 1, 1, 1},     // 0
                                                {0, 1, 1},              // 1
                                                {1, 1, 0, 1, 1, 0, 1},  // 2
                                                {1, 1, 1, 1, 0, 0, 1},  // 3
                                                {0, 1, 1, 0, 0, 1, 1},  // 4
                                                {1, 0, 1, 1, 0, 1, 1},  // 5
                                                {1, 0, 1, 1, 1, 1, 1},  // 6
                                                {1, 1, 1},              // 7
                                                {1, 1, 1, 1, 1, 1, 1},  // 8
                                                {1, 1, 1, 1, 0, 1, 1}}; // 9
/*  
    for(int 




*/

// function prototypes //
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main() {
    int toPrint[MAX_DIGITS], num_digits, i = 0;
    char ch;

    // input the numbers to print
    printf("How many numbers you want to enter?: ");
    scanf("%d", &num_digits);
    for (int i = 0; i < num_digits && i < MAX_DIGITS; i++) 
        scanf("%1d", &toPrint[i]);

    // process the digits in segmenst
    for (int i = 0; i < i < num_digits && i < MAX_DIGITS; i++) 
        process_digit(toPrint[i], i);

    // print the numbers
    


    return 0;
}

// function defintions //
// clear the digits array                     
void clear_digits_array(void) {
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < MAX_DIGITS * 4; j++) 
            digits[i][j] = ' ';
}

// store the segment representation of a digit in a position in digits array
void process_digit(int digit, int position) {
    
}