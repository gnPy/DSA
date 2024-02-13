#include <stdio.h>
#include <stdlib.h>

struct node{
    int val ; 
    struct node *next ; 
} *pos = NULL , *neg = NULL; 

struct node *create(struct node *pos , struct node *neg){
    struct node *temp1 = pos , *temp2 = neg ; 

    int n; 
    printf("ENTER THE NUMBER OF ELEMENTS : ") ; 
    scanf("%d" , &n) ; 
    printf("ENTER THE ELEMENTS  : ") ; 
    for( int i = 0 ; i< n ; i++){
        int x ; 
        scanf("%d" , &x) ; 

        struct node *ptr = malloc(sizeof(struct node )) ; 
        ptr->val = x ; 
        ptr->next = NULL ; 

        if(x >= 0){
            if(temp1 == NULL){
                pos = ptr ; 
                temp1 = ptr ; 
            }
            else{
                temp1->next = ptr ; 
                temp1 = ptr ; 
            }
        }
        else{
            if(temp2 == NULL){
                neg = ptr ; 
                temp2 = ptr ; 
            }
            else{
                temp2->next = ptr ; 
                temp2 = ptr ; 
            }
        }
    }
    if( temp2 != NULL && temp1 != NULL){
        temp2->next = pos ; 
        return neg ; 
    }
    else if( temp1 == NULL){
        return neg ; 
    }
    else{
        return pos ; 
    }
}

void display(struct node *head){
    struct node *temp = head ; 
    while(temp != NULL){
        printf("%d " , temp->val) ; 
        temp = temp->next ; 
    }
    printf("\n") ; 
}

int main(){
    pos = create(pos , neg) ; 
    display(pos) ;
}