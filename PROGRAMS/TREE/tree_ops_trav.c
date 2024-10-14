#include <stdio.h>
#include <stdlib.h>

struct node{
    int val ; 
    struct node *leftchild ; 
    struct node *rightchild ; 
}*root = NULL ;

struct node *insertNode(struct node *p , int key){
    if(p == NULL){
        struct node *newNode = malloc(sizeof(struct node)) ; 
        newNode->leftchild = NULL ; 
        newNode->rightchild = NULL ; 
        newNode->val = key ; 
        p = newNode ; 
    }
    else if( p->val >= key ){
        p->leftchild = insertNode(p->leftchild , key) ; 
    }
    else{
        p->rightchild = insertNode(p->rightchild , key) ; 
    }
    return p ; 
}

void preorder(struct node *head){
    if( head == NULL){
        return  ; 
    }
    
    printf("%d " , head->val) ; 
    preorder(head->leftchild) ; 
    preorder(head->rightchild) ; 
}

void inorder(struct node *head){
    if(head == NULL){
        return  ; 
    }
    inorder(head->leftchild) ; 
    printf("%d " , head->val) ; 
    inorder(head->rightchild) ;
}

void postorder(struct node *head){
    if(head == NULL){
        return  ; 
    }
    postorder(head->leftchild) ; 
    postorder(head->rightchild) ; 
    printf("%d " , head->val) ; 
}

int noOfLeafNodes(struct node *head){
    if(head == NULL){
        return 0; 
    }
    else if ( head->rightchild == NULL && head->leftchild == NULL){
        return 1 ; 
    }
    else{
        return noOfLeafNodes(head->leftchild) + noOfLeafNodes(head->rightchild) ; 
    }
}

void main(){
    int arr[] = {5,3,7,2,4,6,8, 9} ;
    for( int i = 0 ; i < 8; i++){
        root = insertNode(root  , arr[i]) ; 
    } 
    preorder(root) ; printf("\n") ; 
    inorder(root) ; printf("\n") ; 
    postorder(root) ; printf("\n") ; 

    printf("No Of Leaf Childs : %d\n" , noOfLeafNodes(root)) ; 
}
