#include<stdio.h>

#define size 10

int top = -1;
int stack[size];

void pop();
void push();
void display();

void main(){
    while(1){
        int choice;
        printf("Enter 1 for push \n");
        printf("Enter 2 for pop \n");
        printf("Enter 3 for display \n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            default: exit(0);
        }
    }

}

void push()
{
    int x;
    if (top == size - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow!!");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top = top - 1;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Underflow!!");
    }
    else
    {
        printf("Elements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}
