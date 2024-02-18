#include <stdio.h>
#include <stdlib.h>

int n ; 

struct node{
    int val; 
    struct node *next;
}*head = NULL;

struct node *create(struct node *head){
    struct node *temp = head ; 
    printf("ENTER NUMBER OF NODES : ") ;
    scanf("%d",&n) ;
    printf("ENTER THE VALUES : ") ;
    for( int i = 0 ; i< n ; i++){
        struct node *ptr = malloc(sizeof(struct node)) ;
        scanf("%d",&ptr->val) ;
        ptr->next = NULL ;
        if(head == NULL){
            head = ptr ;
            temp = ptr ;
        }
        else{
            temp->next = ptr ;
            temp = ptr ;
        }
    }
    return head ;
}

void display(struct node *head){
    struct node *temp = head ;
    while(temp != NULL){
        printf("%d ",temp->val) ;
        temp = temp->next ;
    }
    printf("\n") ;
}

struct node *clockwiseShift(struct node *head , int k){
    if (k == 0 || head == NULL){
        return head;
    }
    int i = 0 ; 
    struct node *temp = head , *temp2 = head; 
    k = k % n ; 

    if (k == 0){
        return head; 
    }

    while(i < n-k-1){
        temp = temp->next ; 
        i++ ; 
    }
    temp2 = temp->next ;
    temp->next = NULL ;

    temp = temp2 ;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = head ;
    head = temp2 ;
    return head ;    
}

int main(){
    head = create(head) ;
    display(head) ;
    int k ; 
    printf("ENTER THE NUMBER OF SHIFTS : ") ;
    scanf("%d",&k) ;
    head = clockwiseShift(head,k) ;
    display(head) ;
    return 0 ;
}