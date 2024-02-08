#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff ; 
    int pow ; 
    struct node *next ; 
}*poly1 = NULL , *poly2 = NULL , *poly3 = NULL ; 

struct node *createPoly(struct node *head){
    int n ; 
    struct node *temp = head ; 
    printf("ENTER THE NUMBER OF TERMS : ") ; 
    scanf("%d" , &n) ; 
    for( int i = 0 ; i < n ; i++){
        struct node *ptr = malloc(sizeof(struct node)) ; 
        printf("ENTER THE COEFF AND EXPONENT : ") ; 
        scanf("%d %d" , &ptr->coeff , &ptr->pow) ;
        ptr->next = NULL ; 
        if( i == 0){
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

void displayPoly(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->next == NULL){
            printf("%dx^%d", ptr->coeff, ptr->pow);
            break;
        }
        printf("%dx^%d + ", ptr->coeff, ptr->pow);
        ptr = ptr->next;
    }
    printf("\n");
}

void addPoly(struct node *head1 , struct node *head2){
    struct node *temp1 = head1 , *temp2 = head2 , *temp3 = poly3;
    
    while( temp1 != NULL && temp2 != NULL){
        struct node *ptr = malloc(sizeof(struct node )) ; 
        ptr->next = NULL ; 
        if(temp1->pow < temp2->pow){
            ptr->pow = temp1->pow ; 
            ptr->coeff = temp1->coeff ; 
            temp1 = temp1->next ; 
        }
        else if(temp1->pow > temp2->pow){
            ptr->pow = temp2->pow ; 
            ptr->coeff = temp2->coeff ; 
            temp2 = temp2->next ; 
        }
        else{
            ptr->pow = temp1->pow ; 
            ptr->coeff = temp1->coeff + temp2->coeff ; 
            temp1 = temp1->next ; 
            temp2 = temp2->next;  
        }

        if( temp3 == NULL){
            poly3 = ptr ;
            temp3 = ptr ; 
        }
        else{
            temp3->next = ptr ; 
            temp3 = ptr ; 
        }
    }
    while( temp1 != NULL){
        struct node *ptr = malloc(sizeof(struct node )) ; 
        ptr->next = NULL ; 
        ptr->coeff = temp1->coeff ; 
        ptr->pow = temp1->pow ; 
        if(poly3 == NULL){
            poly3 = ptr ; 
            temp3 = ptr ; 
        }
        else{
            temp3->next = ptr ; 
            temp3 = ptr ; 
        }
        temp1 = temp1->next ; 
    }
    while( temp2 != NULL){
        struct node *ptr = malloc(sizeof(struct node )) ; 
        ptr->next = NULL ; 
        ptr->coeff = temp2->coeff ; 
        ptr->pow = temp2->pow ; 
        if(poly3 == NULL){
            poly3 = ptr ; 
            temp3 = ptr ; 
        }
        else{
            temp3->next = ptr ; 
            temp3 = ptr ; 
        }
        temp2 = temp2->next ; 
    }

}

void main(){
    poly1 = createPoly(poly1) ; 
    poly2 = createPoly(poly2) ; 
    printf("POLY 01 : ") ; displayPoly(poly1);  
    printf("POLY 02 : ") ; displayPoly(poly2) ; 
    addPoly(poly1 , poly2) ; 
    printf("POLY 03 : ") ; displayPoly(poly3) ; 

}