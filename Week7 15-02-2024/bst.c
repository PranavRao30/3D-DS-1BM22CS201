#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* root = NULL;

void insert(int a);
void inorder();
void preorder();
void postorder();

void main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
}

void insert(int a){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = a;
    Node* temp = root;
    Node* pare = NULL;
    while(temp != NULL){
        pare = temp;
        if(a > temp->data){
            temp = temp->right;
        }
        else if(a < temp->data){
            temp = temp->left;
        }
        else{
            printf("Invalid data");
            return;
        }
    }
    if(pare == NULL){
        root = newNode;
    }
    else if(a < pare->data){
        pare->left = newNode;
    }
    else{
        pare->right = newNode;
    }
}

void inorder(Node* temp){
    if(temp != NULL){
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void preorder(Node* temp){
    if(temp != NULL){
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(Node* temp){
    if(temp != NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}
