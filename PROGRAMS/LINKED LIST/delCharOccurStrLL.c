#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ch;
    struct node *next;
} *st = NULL;

struct node *convertStrToLL(struct node *head, char *str) {
    struct node *temp = head;
    int i = 0;
    while (*(str + i) != '\0') {
        struct node *ptr = malloc(sizeof(struct node));
        ptr->ch = *(str + i);
        ptr->next = NULL;
        if (head == NULL) {
            head = ptr;
            temp = ptr;
        } else {
            temp->next = ptr;
            temp = ptr;
        }
        i++;
    }
    return head;
}

struct node *delOcc(struct node *head, char ch) {
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL && temp->ch == ch) {
        head = temp->next;
        free(temp);
        temp = head;
    }

    while (temp != NULL) {
        if (temp->ch == ch) {
            if (prev != NULL)
                prev->next = temp->next;
            free(temp);
            temp = prev ? prev->next : head;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

void printLL(struct node *st) {
    struct node *temp = st;
    while (temp != NULL) {
        printf("%c", temp->ch);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("ENTER THE STRING : ");
    fgets(str, 100, stdin);

    st = convertStrToLL(st, str);
    printLL(st);
    st = delOcc(st, 'l');
    printLL(st);

    return 0;
}
