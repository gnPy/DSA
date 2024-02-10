#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head = NULL; 

struct output{
    int smallest;
    int largest;
}*out = NULL;

struct node *create(struct node *head){
    int n ; 
    printf("ENTER THE NUMBER OF NODES : ");
    scanf("%d",&n);
    struct node *temp = head;
    for(int i = 0 ; i < n ; i++){
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER THE DATA : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            temp = head;
        }else{
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

struct output *smallestLargest(struct node *head){
    struct output *out = (struct output *)malloc(sizeof(struct output));
    struct node *temp = head;
    out->smallest = head->data;
    out->largest = head->data;
    while(temp != NULL){
        if(temp->data < out->smallest){
            out->smallest = temp->data;
        }
        if(temp->data > out->largest){
            out->largest = temp->data;
        }
        temp = temp->next;
    }
    return out;
}

void display(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head = create(head);
    display(head);
    out = smallestLargest(head);
    printf("SMALLEST : %d\n",out->smallest);
    printf("LARGEST : %d\n",out->largest);
    return 0;
}

