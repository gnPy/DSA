#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff ; 
    int exp ; 
    struct node *next ;
}; 

struct node *createPoly(struct node *head){
    struct node *temp , *current ; 
    current = head ;
    int n ; 
    printf("ENTER NUMBER OF TERMS IN POLYNOMIAL : ") ;
    scanf("%d",&n) ;

    for(int i = 0 ; i< n ; i++){
        temp = malloc(sizeof(struct node)) ; 
        printf("ENTER COEFFICIENT AND EXPONENT OF TERM %d : ",i+1) ;
        scanf("%d%d",&temp->coeff,&temp->exp) ;
        temp->next = NULL ;

        if(current == NULL){
            current = temp ; 
            head = current ; 
        }
        else{
            current->next = temp ; 
            current = temp ;         
        }
    }
    return head ; 
}

void displayPoly(struct node *head){
    struct node *temp = head ; 
    while(temp != NULL){
        if(temp->next != NULL){
            printf("%dx^%d + ",temp->coeff,temp->exp) ;
        }
        else{
            printf("%dx^%d",temp->coeff,temp->exp); 
        }
        temp = temp->next ;
    }
    printf("\n") ;
}

int main(){
    struct node *head = NULL ; 
    head = createPoly(head) ; 
    displayPoly(head) ;     
}

