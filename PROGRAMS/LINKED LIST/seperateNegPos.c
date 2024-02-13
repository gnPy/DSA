#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *createPoly() {
    int n;
    struct node *pos = NULL, *neg = NULL, *temp1 = NULL, *temp2 = NULL;
    printf("ENTER NUMBER OF ELEMENTS: ");
    scanf("%d", &n);
    printf("ENTER ELEMENTS: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct node *temp = malloc(sizeof(struct node));
        temp->val = x;
        temp->next = NULL;
        if (x < 0) {
            if (neg == NULL) {
                neg = temp;
                temp2 = neg;
            } else {
                temp2->next = temp;
                temp2 = temp2->next;
            }
        } else {
            if (pos == NULL) {
                pos = temp;
                temp1 = pos;
            } else {
                temp1->next = temp;
                temp1 = temp1->next;
            }
        }
    }
    if (neg != NULL && pos != NULL) {
        temp2->next = pos;
        return neg;
    } 
    
    else if (neg != NULL) {
        temp2->next = neg;
        return neg;
    } 
    else {
        temp1->next = pos;
        return pos;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n") ; 
}

int main() {
    struct node *neg = createPoly();
    display(neg);
    return 0;
}
