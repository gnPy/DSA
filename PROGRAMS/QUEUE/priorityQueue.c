#include <stdio.h>

struct queue{
  int front ; 
  int rear ; 
  int size ; 
  int arr[] ; 
}; 

int isFull(struct queue *q){
  return(q->rear == q->size- 1) ; 
}

int isEmpty(struct queue *q){
  return(q->front == q->rear) ; 
}

void dequeue(struct queue *q){
  if(isEmpty(q)){
      printf("Queue is empty\n") ; 
      q->front = -1 ; 
      q->rear = -1 ;
  }
  else{
      q->front++ ; 
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }

  }
}

void enqueue(struct queue *q, int data){
  if(isFull(q)){
      printf("QUEUE IS FULL.\n") ; 
  }
  else if(isEmpty(q)){
      q->rear++ ; 
      q->arr[q->rear] = data ;    
  }
  else{
      int i = q->rear ; 
      while(i >= q->front && q->arr[i] > data){
          q->arr[i+1] = q->arr[i] ; 
          i-- ; 
      }
      q->arr[i+1] = data ; 
      q->rear++ ;

  }
}


void display(struct queue *q){
  if(isEmpty(q)){
      printf("QUEUE IS EMPTY\n") ; 
  }
  else{
      int front ; 
      if(q->front == -1){
          front = 0 ; 
      }
      else{
          front = q->front ; 
      }

      for(int i = front ; i <= q->rear ; i++){
          printf("%d ", q->arr[i]) ; 
      }
      printf("\n") ; 
  }
}

void menu(){
  printf("1. ENQUEUE\n") ; 
  printf("2. DEQUEUE\n") ; 
  printf("3. DISPLAY\n") ; 
  printf("4. EXIT\n") ; 
}

void main(){
  struct queue q ; 
  q.front = -1 ; 
  q.rear = -1 ; 

  printf("ENTER THE SIZE OF THE QUEUE : ") ; 
  scanf("%d", &q.size) ; 
  menu() ;
  int choice = 0 ;
  while(choice != 4){
    printf("ENTER YOUR CHOICE : ") ; 
    scanf("%d", &choice) ; 
    switch(choice){
      case 1 : 
        printf("ENTER THE ELEMENT TO BE INSERTED : ") ; 
        int data ; 
        scanf("%d", &data) ; 
        enqueue(&q, data) ; 
        break ; 
      case 2 : 
        dequeue(&q) ; 
        break ; 
      case 3 : 
        display(&q) ; 
        break ; 
      case 4 : 
        break ; 
      default : 
        printf("INVALID CHOICE\n") ; 
        break ; 
    }
    printf("\n") ; 
  }  
}