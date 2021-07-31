// WAP to reverse any number entered by the user.
#include<stdio.h>
#include<string.h>

int main(){
    char choice[20];
    printf("Do you want to add numbers sequentially or together?\n(Use the exact keywords): ");
    scanf("%s",choice);
    if (strcmp(choice,"sequentially")==0){
        int len;
        printf("Enter how many numbers you want to reverse: ");
        scanf("%d",&len);
        int numArr[len];
        printf("\nEnter the numbers you want to reverse: ");
        for(int i=0; i<len; i++){
            printf("Enter %dth number: ",i+1);
            scanf("%1d",&numArr[i]);
        }
        printf("The reversed sequence of the numbers entered is:\n");
        for (int i=(len-1); i>-1; i--){
            printf("%d ",numArr[i]);
        }
    }
    else if (strcmp(choice,"together")==0){
        int len;
        printf("Enter how many numbers you want to reverse: ");
        scanf("%d",&len);
        int numArr[len];
        printf("Enter the numbers: ");
        for(int i=0;i<len;i++){
            scanf("%1d",&numArr[i]);
        }
        printf("The reversed sequence of the numbers entered is:\n");
        for (int i = (len - 1); i > -1; i--)
        {
            printf("%d ", numArr[i]);
        }
    }
    else{
        printf("Wrong input. Try Again.\n");
    }

    return 0;
}



