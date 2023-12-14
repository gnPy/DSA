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

	if(head == NULL){
		head = ptr ;
		ptr->next =NULL ;  
		} 
	else{
		struct node *temp = head ; 
		while(temp->next != NULL){
			temp = temp->next ; 
			}
		
		temp->next = ptr ; 
		ptr->next = NULL ;
	}
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

void menu(){
	printf("1. ENQUEUE\n") ; 
	printf("2. DEQUEUE\n") ; 
	printf("3. DISPLAY\n") ; 
	printf("4. EXIT\n") ; 
}

int main(){
	int choice ; 
	while(1){
		menu() ; 
		printf("ENTER YOUR CHOICE : ") ; 
		scanf("%d" , &choice) ; 
		switch(choice){
			case 1 : enqueue() ; break ; 
			case 2 : dequeue() ; break ; 
			case 3 : display() ; break ; 
			case 4 : exit(0) ; 
			default : printf("INVALID CHOICE\n") ; 
		}
		printf("\n") ; 
	}
	return 0 ;
}