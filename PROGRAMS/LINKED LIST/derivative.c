#include <stdio.h>
#include <stdlib.h>

int n; 

struct node {
    int coeff;
    int power;
    struct node *next;
} *input = NULL, *output = NULL; 

struct node *createPoly(struct node *head) {
    printf("ENTER THE NUMBER OF TERMS: "); 
    scanf("%d", &n);
    struct node *temp = head;
    for (int i = 0; i < n; i++) {
        struct node *ptr = malloc(sizeof(struct node)); 
        printf("ENTER THE COEFFICIENT AND POWER: ");
        scanf("%d %d", &ptr->coeff, &ptr->power); 
        ptr->next = NULL;
        if (head == NULL) {
            head = ptr;
            temp = ptr;
        } 
        else {
            temp->next = ptr;
            temp = temp->next;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->power); 
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct node *createDerivative(struct node *head, struct node *head2) {
    struct node *temp = head, *temp2 = head2;
    for (int i = 0; i < n; i++) {
        struct node *ptr = malloc(sizeof(struct node)); 
        ptr->next = NULL;
        if (temp->power != 0) {
            ptr->coeff = temp->coeff * temp->power; 
            ptr->power = temp->power - 1;
        } 
        else{
            continue;
        }
        if (head2 == NULL) {
            head2 = ptr;
            temp2 = ptr;
        } 
        else {
            temp2->next = ptr;
            temp2 = temp2->next;
        }
        temp = temp->next; 
    }
    return head2; 
}

int main() {
    input = createPoly(input);
    printf("ORIGINAL POLYNOMIAL: ");
    display(input); 
    output = createDerivative(input, output);
    printf("DERIVATIVE : ");
    display(output);
    return 0;
}
