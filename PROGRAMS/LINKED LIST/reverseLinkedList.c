#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;  
    struct node* next ; 
};

struct node* input(){
    int n ; 
    printf("ENTER THE NUMBER OF NODES IN LL : ") ; 
    scanf("%d" , &n) ; 
    printf("ENTER THE VALUES IN A SINGLE LINE : ") ;

    struct node* head = NULL ; 
    struct node* temp = NULL ; 
    while(n){
        int x ; scanf("%d" , &x) ; 
        struct node* temp2 = malloc(sizeof(struct node)) ; 
        if( head == NULL){
            head = temp2 ; 
            temp = head ; 
        }
        else{
            temp->next = temp2 ; 
            temp = temp->next ; 
        }
        temp2->val= x ; 
        temp2->next = NULL ; 
        --n ; 
    }
    return head ; 
}

struct node* reverse(struct node* alpha , struct node* beta){
    if(beta == NULL){
        return alpha ; 
    }
    else{
        struct node* head = reverse(beta , beta->next) ; 
        beta->next = alpha ; 
        return head ; 
    }

}

void display(struct node* head){
    struct node* temp = head ; 
    while(temp != NULL){
        printf("%d " , temp->val) ; 
        temp = temp->next ; 
    }
    printf("\n") ; 
}

int main(){
    struct node* head = input() ; 
    display(head) ; 
    head = reverse(NULL , head) ; 
    display(head) ; 
    return 0 ; 
}