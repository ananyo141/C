// WAP to find max of numbers and return.

#include<stdio.h>

// when an array is passed to a function as an argument, it is passed as a pointer at which point
// the information about it's size is lost. So, 'sizeof(arr)/sizeof(arr[0])' can't be used.
float findMax(float num_arr[],int array_length){
    float curr_choice = num_arr[0];
    for(int i=0;i<array_length;i++){
        if (num_arr[i]>curr_choice){
            curr_choice=num_arr[i];
        }
    }
    return curr_choice;
}

float findMin(float num_arr[],int array_length){
    float curr_choice = num_arr[0];
    for (int i=0; i<array_length; i++){
        if (num_arr[i]< curr_choice){
            curr_choice = num_arr[i];
        }
    }
    return curr_choice;
}

int main(void){
    int howMany;
    printf("How many numbers do you want to process?: ");
    scanf("%d",&howMany);
    float num[howMany];
    for(int i = 0;i<howMany;i++){
        float inp;
        printf("\nEnter the number: ");
        scanf("%f", &inp);
        num[i]=inp;
    }
    float max = findMax(num,howMany);
    float min = findMin(num,howMany);
    printf("The max of the numbers you entered is: %.2f, and the min is %.2f\n",max,min);

    return 0;
}