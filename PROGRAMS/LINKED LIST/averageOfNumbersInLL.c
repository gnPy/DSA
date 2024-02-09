#include <stdio.h>
#include <stdlib.h>

int n ; 

struct node{
    float data ; 
    struct node *next ; 
} *head = NULL;

struct node *create(struct node *head){
    struct node *new_node, *temp ; 
    printf("ENTER THE NUMBER OF NODES : ") ; 
    scanf("%d", &n) ; 
    for(int i = 0 ; i < n ; i++){
        new_node = (struct node *)malloc(sizeof(struct node)) ; 
        printf("ENTER ELEMENT : ") ; 
        scanf("%f", &new_node->data) ; 
        new_node->next = NULL ; 
        if(head == NULL){
            head = new_node ; 
            temp = head ; 
        }
        else{
            temp->next = new_node ; 
            temp = new_node ; 
        }
    }
    return head ; 
}

float average(struct node *head){
    if(head == NULL){
        return 0 ; 
    }
    else{
        return (head->data + average(head->next)) ; 
    }
}

int main(){
    float avg ; 
    head = create(head) ; 
    avg = average(head) ; 
    printf("THE AVERAGE OF THE NUMBERS IS : %f\n", avg/n) ; 
    return 0 ;
}