#include <stdio.h>

struct queue{
	int size ; 
	int rear ; 
	int front ; 
	int arr[100] ; 
	};

int isFull(struct queue *q){
	return (q->rear == q->size -1) ;  
	}

int isEmpty(struct queue *q){
	return ( q->front == q->rear) ; 
	}

void enqueue(struct queue *q , int n){
	if(isFull(q)){
		printf("QUEUE IS FULL.\n") ;  
		}
	else{
		q->arr[++(q->rear)] = n ;
		} 
	}	

void dequeue(struct queue *q){
	if(isEmpty(q)){
		 printf("THE QUEUE IS EMPTY.\n") ;  	 		 
		}
	else{
		printf("%d\n" , q->arr[++(q->front)]);
		}
	}

void display(struct queue *q){
	if( isEmpty(q)){
		printf("QUEUE IS EMPTY.\n") ; 
		}
	else{

		for( int i = q->front+1 ; i <= q->rear ; i++){
			printf("%d " , q->arr[i]) ; 
			}
		printf("\n") ; 
		}
	} 

void displayMenu() {
    printf("\n------ MENU ------\n");
    printf("1. ENQUEUE\n");
    printf("2. DEQUEUE\n");
    printf("3. DISPLAY\n");
    printf("4. EXIT\n");
    printf("-------------------\n");
}

int main() {
    struct queue q;
    q.front = q.rear = -1; 

    printf("ENTER THE SIZE OF QUEUE : ");
    scanf("%d", &q.size);

    int choice = 0, n;

    while(choice != 4){
        displayMenu();
        printf("ENTER CHOICE : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER THE ELEMENT : ");
                scanf("%d", &n);
                enqueue(&q, n);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("EXITING.\n");
                break;

            default:
                printf("WRONG CHOICE.\n");
        }
    }
}
















