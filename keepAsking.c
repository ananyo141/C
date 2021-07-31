// WAP to ask the user a question and keep asking yes/no until user chooses yes.
#include<stdio.h>
#include<conio.h>

void keepAsking(char questn[50]){
    printf("Enter your answer in one word(Yes/No): ");
    char ans[20];
    scanf("%s",ans);

    // Equivalent for-loop:
    // for (ans;(*ans != *"Yes") || (*ans != *"yes"); scanf("%s", ans))
    // {
    //     printf("%s\n",questn);
    // }

    // An important line. || Operator doesn't work (infinite loop). Have to use &&.
    while ((*ans != *"Y") && (*ans != *"y"))
    {
        printf("\n%s\n", questn);
        printf("Enter your answer in one word(Yes/No): ");
        scanf("%s", ans);
    }
    printf("\nThe user said 'YES'!\n");
}

int main(){
    char question[50];
    printf("Enter the question: ");
    fgets(question,50,stdin);
    keepAsking(question);
    return 0;
}
