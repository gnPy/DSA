#include <stdio.h>
#include <stdlib.h>

int size ; 

struct node{
    int data ; 
    struct node *next ; 
}; 

struct hash{
    struct node *chain[100] ; 
} ; 

void init(struct hash *ht){
    for( int i = 0 ; i< size ; i++){
        ht->chain[i] = NULL ; 
    }
}

void insert(struct hash *ht , int x){
    int pos = x%size ; 

    struct node *ptr = malloc(sizeof(struct node)) ; 
    ptr->next = NULL ; 
    ptr->data = x ; 

    if(ht->chain[pos] == NULL){
        ht->chain[pos] = ptr ; 
    }
    else{
        struct node *temp = ht->chain[pos] ; 
        while(temp->next != NULL){
            temp = temp->next ; 
        }
        temp->next = ptr ; 
    }
}

void printHash(struct hash *ht){
    for( int i = 0 ; i < size ; i++){
        printf("%d--->" , i) ; 
        
        struct node *temp = ht->chain[i] ; 
        while(temp != NULL){
            printf("%d-", temp->data) ;
            temp = temp->next ;  
        }
        printf("NULL\n") ; 
    }
}

int main(){
    printf("ENTER THE SIZE OF THE HASH TABLE : ") ; 
    scanf("%d" , &size) ; 

    struct hash ht ; 
    init(&ht) ; 

    int n ; 
    printf("ENTER THE NUMBER OF ELEMENTS : ") ; 
    scanf("%d" , &n) ; 
    printf("ENTER THE ELEMENTS : ") ; 
    for( int i = 0 ; i < n ; i++){
        int x ; 
        scanf("%d" , &x) ; 
        insert(&ht , x) ; 
    }

    printHash(&ht) ; 
}



