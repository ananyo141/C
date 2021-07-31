// WAP to create a nested array(2D) and a nested loop to print all the elements in it.

#include<stdio.h>

void print2DIntArr(int arr[4][2]){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\n", arr[i][j]);
        }
    }
}

void print2DCharArr(char *arr[4][2]){
    for (int i=0; i<4; i++){
        for (int j = 0;j < 2; j++){
            printf("%s\n", arr[i][j]);
        }
    }
}

int main(){
    int numbers[4][2] = {{1, 1}, {1, 2}, {1, 3}, {1, 4}};
    print2DIntArr(numbers);
    char *movies[4][2]={{"arrival","denis"},{"mullholland dr","lynch"},{"nightcrawler","dan"},{"gifted","webb"}};
    print2DCharArr(movies);
    return 0;
}
