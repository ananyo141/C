// WAP to calculate the check code for European Article Number //

/* Add the second, fourth, sixth, eighth, tenth and twelfth digits.
Add the first, third, fifth, seventh, ninth and eleventh digits.
Multiply the first sum by 3 and add it to the second sum.
Subtract 1 from total.
Compute the remainder when the adjusted total is divided by 10.
Subtract the remainder from 9. */

#include<stdio.h>
#define CODE_LEN 12

// just spent hours figuring out why the code got stuck in an infinite loop (crash),
// only to figure out: (also, this is not gradual as python, as printf method suggested there was
// something wrong with the scanf statement in main() function.
int generateEANCheck(int code[CODE_LEN]){
    int firstSum=0, secondSum=0;
    for (int i = 1; i< CODE_LEN; i+=2){     // hadn't added the = sign,
        firstSum+=code[i];
    }
    for (int i = 0; i < CODE_LEN; i+=2){    // just incremented without saving the value (i+2)
        secondSum+=code[i]; 
    }
    int total= (firstSum*3) + secondSum; total-=1;
    int remainder = total%10;
    return (9-remainder);
}

int main(){
    int EANCode[CODE_LEN];
    printf("Enter the 12 Digit EAN code: ");
    for (int i=0; i<CODE_LEN; i++){
        scanf("%1d",&EANCode[i]);
    }
    int check=generateEANCheck(EANCode);
    printf("The required EAN check code is: %d\n",check);

    return 0;
}