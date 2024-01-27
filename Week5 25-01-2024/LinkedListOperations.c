#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;

void insertAtEnd(struct Node* *head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int newVal;
    scanf("%d", &newVal);
    newNode->data = newVal;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void sortList(struct Node* *head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        while (temp != NULL) {
            if (current->data > temp->data) {
                int swap = current->data;
                current->data = temp->data;
                temp->data = swap;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

void reverseList(struct Node* *head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void concatenate(struct Node* head1, struct Node* head2) {
    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

int main() {
    int l1, l2;

    printf("Enter length of First linked list: ");
    scanf("%d", &l1);

    printf("Enter length of Second linked list: ");
    scanf("%d", &l2);

    printf("Enter first linked list: ");
    for(int i = 0; i < l1; i++){
        insertAtEnd(&head1);
    }

    printf("Enter second linked list: ");
    for(int i = 0; i < l1; i++){
        insertAtEnd(&head2);
    }

    printf("First linked list: ");
    display(head1);

    printf("\nSecond linked list: ");
    display(head2);

    sortList(&head1);
    printf("\nSorted linked list: ");
    display(head1);

    reverseList(&head2);
    printf("\nReversed linked list: ");
    display(head2);

    concatenate(head1, head2);
    printf("\nConcatenated linked list: ");
    display(head1);

    return 0;
}
