#include <stdio.h>

int items[100];
int front = -1;
int rear = -1 ; 
int size = 100 ;

int isFull() {
  return (front == rear + 1) || (front == 0 && rear == size - 1);
}

int isEmpty() {
  return (front == -1);
}

void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1){
        front = 0;
    }
    rear = (rear + 1) % size;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } 
  else{
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 

    else {
      front = (front + 1) % size;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % size) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

void menu() {
  printf("\n\n Circular Queue:\n");
  printf("1. Insert \n");
  printf("2. Delete \n");
  printf("3. Display \n");
  printf("4. Exit \n");
}

int main() {
  int choice, element;
  do {
    menu();
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("\n Enter the element to be inserted : ");
        scanf("%d", &element);
        enQueue(element);
        break;
      case 2:
        deQueue();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exit\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 4);
  return 0;
}