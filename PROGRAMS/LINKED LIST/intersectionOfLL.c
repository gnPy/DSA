#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ; 
    struct node *next ; 
}*head1 = NULL , *head2 = NULL , *head3 = NULL;

struct node *create(struct node *head){
    int n ; 
    printf("ENTER THE NUMBER OF NODES : ");
    scanf("%d",&n);
    struct node *temp = head;
    printf("ENTER THE VALUES : ") ; 
    for(int i = 0 ; i < n ; i++){
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        //printf("ENTER THE DATA : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            temp = head;
        }else{
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

int getMaximum(struct node *head){
    struct node *temp = head;
    int max = 0;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void display(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *intersection(struct node *head1 , struct node *head2, struct node *head3){
    struct node *temp1 = head1 , *temp2 = head2 , *temp3 = head3;
    int max = getMaximum(head1) > getMaximum(head2) ? getMaximum(head1) : getMaximum(head2);
    int arr[max+1];
    for(int i = 0 ; i < max+1 ; i++){
        arr[i] = 0;
    }
    while(temp1 != NULL){
        arr[temp1->data]++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        if(arr[temp2->data] > 0){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = temp2->data;
            newNode->next = NULL;
            if(head3 == NULL){
                head3 = newNode;
                temp3 = head3;
            }else{
                temp3->next = newNode;
                temp3 = temp3->next;
            }
        }
        temp2 = temp2->next;
    }
    return head3;
}

int main(){
    head1 = create(head1);
    head2 = create(head2);
    printf("LIST 1 : ");
    display(head1);
    printf("LIST 2 : ");
    display(head2);
    head3 = intersection(head1,head2,head3);
    printf("INTERSECTION : ");
    display(head3);
    return 0;
}





