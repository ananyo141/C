// Take five quiz grades of students, compute total score and average for each student
// average, high score and low score for each quiz.
#include <stdio.h>

// This program is correct according to the short-span of testing that entailed during production. 
// Suggest further testing //
int main() {
    float studentGrades[5][5];
    // fill in the student marks details
    for (int i = 0; i < 5; i++) {
        printf("Prepare Student %d details: \n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Enter quiz %d number: ", j + 1);
            scanf("%f", &studentGrades[i][j]);
            if (studentGrades[i][j] > 100) {
                printf("Invalid details entered.\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        float studentTotal = 0;
        printf("Test Analysis for Student %d:\n", i);
        for (int j = 0; j < 5; j++) 
            studentTotal += studentGrades[i][j];
        printf("Total marks scored by Student-%d: %.2f\n", i + 1, studentTotal);
        printf("Average: %.2f\n", studentTotal/5);
    }

    // find out average, high score, low score for each quiz
    for (int i = 0; i < 5; i++) {
        float highScore;
        float lowScore;
        float quizTotal = 0;
        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                highScore = studentGrades[j][i];
                lowScore = studentGrades[j][i];
            }

            highScore = (studentGrades[j][i] > highScore) ? studentGrades[j][i] : highScore;
            lowScore = (studentGrades[j][i] < lowScore) ? studentGrades[j][i] : lowScore;
            quizTotal += studentGrades[j][i];
        }
        
        printf("For Quiz:%d,\nAverage = %.2f, Highest Score = %.2f, Lowest Score = %.2f\n", i+1, \
        quizTotal/5, highScore, lowScore);
    }

    return 0;
}