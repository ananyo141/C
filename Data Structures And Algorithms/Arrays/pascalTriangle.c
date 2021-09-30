// Recreate the Pascal's Triangle 
#include <stdio.h>

int main() {
    int rowNum;
    printf("Enter the number of rows you want to create Pascal's Triangle: ");
    scanf("%d", &rowNum);
    int row, col;
    int **const pascalTriangle = malloc(sizeof(int) * (rowNum * rowNum + 1));    

    // Loop to form the pascal triangle and store in array
    for (row = 0; row < rowNum; row++) {
        pascalTriangle[row][0] = 1;       // set every first element of row to 1
        for (col = 1; col <= row; col++)  // cell value is equal to sum of one cell up and one cell diag up to left
            pascalTriangle[row][col] = pascalTriangle[row - 1][col] + pascalTriangle[row - 1][col - 1];
        if (row < rowNum - 1)
            pascalTriangle[row][col] = 0; // set every last (column + 1) to be (invisibly) 0, so that next row column
    }                                     // can add the empty cell as 0 (skip last row since that index in unbounded)

    // Print the pascal triangle
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j <= i; j++) 
            printf("%-4d", pascalTriangle[i][j]);
        printf("\n");
    }

    free(pascalTriangle);

    return 0;
}
