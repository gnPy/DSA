#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
} *head = NULL;

struct term {
    int pos;
    int neg;
};

struct term *hashSet[100];

struct node *createPoly(struct node *head) {
    int n;
    printf("ENTER NUMBER OF ELEMENTS IN THE LIST: ");
    scanf("%d", &n);
    struct node *temp = head;
    printf("ENTER THE ELEMENTS: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct node *newNode = malloc(sizeof(struct node));
        newNode->val = x;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    if (head != NULL)  
        temp->next = head;
    return head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("THE LIST IS: ");
    do {
        printf("%d ", temp->val);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void repeatedElements(struct node *head) {
    struct node *temp = head;
    for (int i = 0; i < 100; i++) {
        hashSet[i] = NULL;
    }
    do {
        int x = temp->val;

        if (x >= 0) {
            if (hashSet[x] == NULL) {
                struct term *ptr = malloc(sizeof(struct term));
                ptr->pos = 1;
                ptr->neg = 0;
                hashSet[x] = ptr;
            } else {
                hashSet[x]->pos++;
            }
        } 
        else {
            if (hashSet[-x] == NULL) {
                struct term *ptr = malloc(sizeof(struct term));
                ptr->pos = 0;
                ptr->neg = 1;
                hashSet[-x] = ptr;
            } else {
                hashSet[-x]->neg++;
            }
        }
        temp = temp->next;
    } while (temp != head);

    for (int i = 0; i < 100; i++) {
        if (hashSet[i] != NULL) {
            if (hashSet[i]->pos > 1) {
                printf("%d HAS REPEATED %d TIMES.\n", i , hashSet[i]->pos);
            }
            if (hashSet[i]->neg > 1) {
                printf("%d HAS REPEATED %d TIMES.\n", -i , hashSet[i]->neg);
            }
        }
    }
}

int main() {
    head = createPoly(head);
    display(head);
    repeatedElements(head);
}