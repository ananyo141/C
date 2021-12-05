// Implement Tower of Hanoi Using Recursion

#include <stdio.h>

void TowerOfHanoi(int num, char source, char dst, char spare) {
    /* Move num disks from source to dst with the help of spare */
    if (num == 1) 
        printf("Move from %c to %c\n", source, dst);    // if just 1 disk, move
    else {                                              // from src to dst, else,
        TowerOfHanoi(num-1, source, spare, dst);        // move n-1 from source to spare
        TowerOfHanoi(1    , source, dst, spare);        // move 1 disk from source to dst
        TowerOfHanoi(num-1, spare, dst, source);        // move stacked n-1 from spare to dst
    }
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    TowerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}

