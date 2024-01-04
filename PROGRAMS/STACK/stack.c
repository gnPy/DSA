#include <stdio.h>

struct stack{
	int top;  
	int size ; 
	int arr[100] ; 
	}; 

int isFull(struct stack *st){
	return (st->size == st->top +1) ; 
	}

int isEmpty(struct stack *st){
	return (st->top == -1) ;  
	}

void push(struct stack *st , int ele){
	if(isFull(st)){
		printf("STACK IS FULL.\n") ; 
		}
	else{
		st->arr[++(st->top)] = ele ; 
		}
	}

void pop(struct stack *st){
	if(isEmpty(st)){
		printf("STACK IS EMPTY.\n") ; 
		}	
	else{
		st->arr[(st->top)--]; 
		} 
	}			

void peek(struct stack *st){
	if(isEmpty(st)){
		printf("STACK IS EMPTY.") ; 
		}
	else{
		printf("%d\n" ,st->arr[st->top]) ;
		}
	}

void display(struct stack *st){
	if(isEmpty(st)){
		printf("STACK IS EMPTY.\n") ; 
		}
	else{
		for(int i = st->top ; i >= 0 ; i--){
			printf("%d\n" , st->arr[i]) ; 
			}
		}
	}

void displayMenu() {
    printf("\n------ MENU ------\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PEEK\n");
	printf("4. DISPLAY\n");
    printf("5. EXIT\n");
    printf("-------------------\n");
}

int main() {
    struct stack st;
    st.top = -1; 
    
	printf("ENTER THE SIZE OF STACK : ") ; 
	scanf("%d" , &st.size) ; 

    int choice = 0, ele;
	displayMenu() ;
    while (choice != 5){
        printf("ENTER THE CHOICE : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER THE NUMBER : ");
                scanf("%d", &ele);
                push(&st, ele);
                break;

            case 2:
                pop(&st);
                break;

            case 3:
                peek(&st);
                break;

            case 4:
                display(&st);
                break;
			
			case 5:
				printf("EXITING.\n") ;
				break ;

            default:
                printf("WRONG CHOICE.\n");
		}
		printf("\n") ; 
	}
}
