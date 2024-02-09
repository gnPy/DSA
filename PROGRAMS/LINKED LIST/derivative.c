#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff ; 
    int power ; 
    struct node *next ; 
}*head = NULL ; 

struct node *createPoly(struct node *head){
    int n ; 
    printf("ENTER THE NUMBER OF TERMS : ") ; 
    scanf("%d",&n) ;
    struct node *temp = NULL ;
    for( int i = 0 ; i< n ; i++){
        struct node *ptr = malloc(sizeof(struct node)) ;
        printf("ENTER THE COEFF AND POWER : " );
        scanf("%d %d",&ptr->coeff,&ptr->power) ; 
        temp->next = NULL ;
        if(i == 0){
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
    while(temp->next != NULL){
        printf("%dx^%d + ",temp->coeff,temp->power) ; 
        temp = temp->next ; 
    }
    printf("%dx^%d\n",temp->coeff,temp->power) ;
}

struct node *createPolyDerivative(struct node *head){
    
}
