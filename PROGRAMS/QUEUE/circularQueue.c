#include <stdio.h>

int items[100];
int front = -1;
int rear = -1 ; 
int size ; 

int isFull() {
  return (front == rear + 1) || (front == 0 && rear == size - 1);
}

int isEmpty() {
  return (front == -1);
}

void enQueue(int element) {
  if (isFull()){
    printf("QUEUE IS FULL \n");
  }
  else {
    if (front == -1){
        front = 0;
    }
    rear = (rear + 1) % size;
    items[rear] = element;
  }
}
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("QUEUE IS EMPTY\n");
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
    return (element);
  }
}
void display() {
  int i;
  if (isEmpty()){
    printf("QUEUE IS EMPTY\n");
  }
  else {
    for (i = front; i != rear; i = (i + 1) % size) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
  }
}

void menu() {
  printf("CHOICES...\n");
  printf("1. INSERT \n");
  printf("2. DELETE \n");
  printf("3. DISPLAY \n");
  printf("4. EXIT \n");
}

int main() {
  int choice , element ;
  printf("ENTER THE SIZE OF QUEUE : ");
  scanf("%d", &size);

  do {
    menu();
    printf("ENTER YOUR CHOICE :");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("ENTER ELEMENT TO BE INSERTED : ");
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
        printf("EXIT\n");
        break;
      default:
        printf("INVALID CHOICE\n");
    }
  printf("\n") ;
  } while (choice != 4);
  return 0;
}