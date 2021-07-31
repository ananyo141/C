// WAP to check the last digit of the UPC code entered by the user.
// Add first,third,fifth,seventh,ninth, and eleventh digits. Add the second, fourth, sixth,
//  eighth, and tenth digits.
// Multiply the first sum by 3 and add it to the second sum.
// Subtract 1 from total.
// Compute the remainder when the adjusted total is divided by 10. 
// Subtract the remainder from 9.
#include<stdio.h>
#define CODE_LEN 11

int generateCheckCode(int numberArr[CODE_LEN]){
    int firstSum=0, secondSum=0;
    for (int i = 0; i < CODE_LEN; i += 2){
        firstSum+=numberArr[i];
    }
    for (int i = 1; i < CODE_LEN; i += 2){
        secondSum += numberArr[i];
    }
    int totalSum = firstSum*3 + secondSum-1;
    int remainder = totalSum % 10;
    int result = 9-remainder;
    return result;
}

int main(){
    int numArr[CODE_LEN], givenCheck;
    printf("Enter the 11 digit UPC code: ");
    for(int i = 0 ;i < CODE_LEN ; i++) {
        printf("Enter %d-th digit: ",i+1);
        scanf("%d", &numArr[i]);
    }
    printf("Enter the check code: ");
    scanf("%d", &givenCheck);
    int checkCode = generateCheckCode(numArr);
    printf("The check code of the entered UPC code is: %d\n",checkCode);
    
    printf((checkCode == givenCheck ? "Valid\n" : "Invalid\n"));
    return 0;
}

