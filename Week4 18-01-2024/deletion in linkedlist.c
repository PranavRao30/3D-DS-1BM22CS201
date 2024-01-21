#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void pop();
void end_delete();
void delete_at_pos();
void display();
void append();

int main() {
    int choice;
    while (1) {
        printf("1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Delete at position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                append();
                break;
            case 2:
                pop();
                break;
            case 3:
                end_delete();
                break;
            case 4:
                delete_at_pos();
                break;
            case 5:
                display();
                break;
            default:
                printf("Exiting the program");
                return 0;
        }
    }
}

void append() {
    Node* temp = (Node*)malloc(sizeof(Node));
    int new_data;
    printf("Enter data in the new node: ");
    scanf("%d", &new_data);
    temp->data = new_data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    Node* temp1 = head;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void pop() {
    if(head == NULL){
        printf("Linked List is empty");
        return;
    }
    head = head->next;
}

void end_delete() {
    if(head == NULL){
        printf("Linked List is empty");
        return;
    }
    if(head->next == NULL){
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* temp1 = head;
    temp = temp->next;
    while(temp->next != NULL){
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp1->next = NULL;
}

void delete_at_pos() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    Node* temp = head;
    while(--pos){
        temp = temp->next;
        if(temp->next = NULL){
            printf("Not enough elements");
        }
    }
    Node* temp1 = temp;
    temp1 = temp1->next;
    if(temp1->next == NULL){
        printf("Not enough elements");
    }
    temp1 = temp1->next;
    temp->next = temp1;
}

void display() {
    Node* temp1 = head;
    while (temp1 != NULL) {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL\n");
}
