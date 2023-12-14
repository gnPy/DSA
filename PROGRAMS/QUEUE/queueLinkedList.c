#include <stdio.h>
#include <stdlib.h>

struct node {
	int data ; 
	struct node *next ; 
	}*head = NULL ; 

void display(){
	struct node *ptr ; 
	ptr = head ; 
	while(ptr!= NULL){
		printf("%d " , ptr->data) ; 
		ptr = ptr->next ; 
		}
	printf("\n") ; 
	}

void enqueue(){
	struct node *ptr ; 
	ptr = malloc(sizeof(struct node)) ; 
	printf("ENTER THE ELEMENT TO BE INSERTED  : ") ; 
	scanf("%d" , &ptr->data) ; 

	struct node *temp = head ; 
	while(temp->next != NULL){
		temp = temp->next ; 
		}
	
	temp->next = ptr ; 
	ptr->next = NULL ;
	}	

void dequeue(){
	if(head == NULL){
		printf("QUEUE EMPTY\n") ; 
	}
	else{
		struct node *temp= head ; 
		head = head->next ; 
		free(temp);  
	}
}

void search(){
	int x, i = 0 ; 
	struct node *temp = head ; 
	printf("ENTER THE ELEMENT TO BE SEARCHED : ") ; 
	scanf("%d", &x) ; 

	while(temp != NULL){
		if( temp->data == x){
			printf("POSITION IS : %d\n" , i+1) ; 
			break ; 
			}
		i++ ; 
		temp = temp->next ; 
		}
	if(temp == NULL){
		printf("ELEMENT NOT FOUND.\n") ; 
		}
	}

void menu(){
	printf("1. CREATE\n") ; 
	printf("2. DISPLAY\n") ; 
	printf("3. INSERT AT FRONT\n") ; 
	printf("4. INSERT AT END\n") ; 
	printf("5. INSERT BETWEEN\n") ; 
	printf("6. DELETE FRONT\n") ; 
	printf("7. DELETE END\n") ; 
	printf("8. SEARCH\n") ; 
	printf("9. EXIT\n") ; 
	}


int main(){
	int choice ; 
	menu() ; 
	while(1){
		printf("ENTER YOUR CHOICE : ") ; 
		scanf("%d" , &choice) ; 
		switch(choice){
			case 1 : create() ; 
				 break ; 
			case 2 : display() ; 
				 break ; 
			case 3 : insertFront() ; 
				 break ; 
			case 4 : insertEnd() ; 
				 break ; 
			case 5 : insertBetween() ; 
				 break ; 
			case 6 : deleteFront() ; 
				 break ; 
			case 7 : deleteEnd() ; 
				 break ; 
			case 8 : search() ; 
				 break ; 
			case 9 : exit(0) ; 
				 break ; 
			default : printf("INVALID CHOICE\n") ; 
				  break ; 
			}
		printf("\n") ; 
		}
	return 0 ; 
	}