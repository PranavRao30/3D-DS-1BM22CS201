#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("Before swapping, a = %d and b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping, a = %d and b = %d", a, b);
}
