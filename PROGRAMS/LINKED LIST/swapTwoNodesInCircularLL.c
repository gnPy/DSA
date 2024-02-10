#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head = NULL;

struct node *create(struct node *head){
    struct node *newNode, *temp = head;
    int n, data;
    printf("ENTER NUMBER OF NODES : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER THE DATA : " );
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            temp = head;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head;
    return head;
}

void display(struct node *head){
    struct node *temp = head ; 
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

struct node *swap(struct node *head){
    int x , y ; 
    printf("ENTER THE TWO NODES POSITIONS TO SWAP : ");
    scanf("%d %d", &x, &y);
    struct node *temp = head, *prevX = NULL, *prevY = NULL, *X = NULL, *Y = NULL;
    for(int i = 1; i < x; i++){
        prevX = temp;
        temp = temp->next;
    }
    X = temp;
    temp = head;
    for(int i = 1; i < y; i++){
        prevY = temp;
        temp = temp->next;
    }
    Y = temp;

    if(prevX != NULL){
        prevX->next = Y;
    }
    else{
        head = Y;
    }
    if(prevY != NULL){
        prevY->next = X;
    }
    else{
        head = X;
    }
    struct node *temp1 = X->next;
    X->next = Y->next;
    Y->next = temp1;
    return head;
}

void main{
    head = create(head);
    display(head);
    head = swap(head);
    display(head);
}