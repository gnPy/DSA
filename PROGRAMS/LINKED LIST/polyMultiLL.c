#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int pow;
    struct node *next;
}*poly1 = NULL , *poly2 = NULL , *poly3 = NULL; 


int createPoly1(){
    int n , i , m = 0; 
    struct node *ptr, *temp = poly1;
    printf("ENTER NUMBER OF TERMS IN POLYNOMIAL 1 : ");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        ptr = malloc(sizeof(struct node));
        printf("ENTER COEFFICIENT AND POWER : ");
        scanf("%d %d", &ptr->coeff, &ptr->pow);
        if(i == 0){
            poly1 = ptr;  
            ptr->next = NULL;
            temp = ptr;
        }
        else{
            temp->next = ptr;
            ptr->next = NULL;
            temp = ptr;
        }
        if(ptr->pow > m){
            m = ptr->pow;
        }       
    }
    return m;
}

int createPoly2(){
    int n , i , m = 0; 
    struct node *ptr, *temp = poly2;
    printf("ENTER NUMBER OF TERMS IN POLYNOMIAL 2 : ");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        ptr = malloc(sizeof(struct node));
        printf("ENTER COEFFICIENT AND POWER : ");
        scanf("%d %d", &ptr->coeff, &ptr->pow);
        if(i == 0){
            poly2 = ptr;  
            ptr->next = NULL;
            temp = ptr;
        }
        else{
            temp->next = ptr;
            ptr->next = NULL;
            temp = ptr;
        }
        if(ptr->pow > m){
            m = ptr->pow;
        }       
    }
    return m;
}
void createPolyFromHash(int hash[]){
    struct node *ptr , *temp = poly3 ;

    for(int i = 0 ; i<=100 ; i++){
        if(hash[i] != 0){
            ptr = malloc(sizeof(struct node));
            ptr->coeff = hash[i];
            ptr->pow = i;
            ptr->next = NULL;

            if(temp == NULL){
                poly3 = ptr;
                temp = ptr;
            }
            else{
                temp->next = ptr;
                temp = ptr;
            }
        }
    }
}

void displayPoly(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%dx^%d + ", ptr->coeff, ptr->pow);
        ptr = ptr->next;
    }
    printf("\n");
}

void multiplyPoly(struct node *head1 , struct node *head2 , int m){
    struct node *ptr1 , *ptr2 ; 
    ptr1 = head1 ; 
    ptr2 = head2 ; 

    int hash[100] = {0};

    for (ptr1 = head1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = head2; ptr2 != NULL; ptr2 = ptr2->next) {
            int c = ptr1->coeff * ptr2->coeff;
            int p = ptr1->pow + ptr2->pow;
            hash[p] += c;
        }
    }

    createPolyFromHash(hash);

}

int main(){
    int m1 = createPoly1();
    int m2 = createPoly2();

    printf("POLYNOMIAL 1 : ");
    displayPoly(poly1);
    printf("POLYNOMIAL 2 : ");
    displayPoly(poly2);

    int m = (m1 > m2) ? m1 : m2;

    multiplyPoly(poly1 , poly2 , m);

    printf("MULTIPLIED POLYNOMIAL : ");
    displayPoly(poly3);

}


