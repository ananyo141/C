// Write a countdown sequence with the use of do-while statement.

#include<stdio.h>
#include<unistd.h>          // this provides the 'sleep()' function

int main(){
    int startNum;
    printf("Enter where you want to start the countdown from: ");
    scanf("%d",&startNum);
    do {
        printf("T minus %d seconds...\n",startNum--);
        sleep(1);
    } while (startNum != 0);
    printf("Blastoff!\n");

    return 0;
}