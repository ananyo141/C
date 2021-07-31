// WAP to say 'Hello' to a user who enters name and age.
#include<stdio.h>
#include<stdlib.h>

void sayHello(char name[20]){
    printf("Hello! %s",name);
}
void sayAge(int age){
    printf("Your age is %d\n",age);
}

int main(){
    char name[20];
    int age;
    printf("Please enter your name: ");
    fgets(name,20,stdin);
    printf("Please enter your age: ");
    scanf("%d",&age);
    system("clear");
    sayHello(name);
    sayAge(age);

    
    return 0;
}