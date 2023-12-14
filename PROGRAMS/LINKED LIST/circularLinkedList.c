#include <stdio.h>
#include <stdlib.h>

struct node {
	int data ; 
	struct node *next ; 
	}*head = NULL ; 

void display(){
	struct node *ptr ; 
	ptr = head ; 
	if(head == NULL){
		printf("LIST IS EMPTY\n") ; 
		}
	else{
		while(ptr->next != head){
			printf("%d " , ptr->data) ; 
			ptr = ptr->next ; 
			}
		printf("%d " , ptr->data) ; 
		}
	}

void insertFront(){
	struct node *ptr ;
	ptr = malloc(sizeof(struct node)) ;  
	printf("ENTER THE ELEMENT TO BE INSERTED : ") ; 
	scanf("%d" , &ptr->data) ;
	
	if( head == NULL){
		head = ptr ; 
		ptr->next = ptr ; 
	}
	else{
		struct node *temp = head ; 
		while(temp->next != head){
			temp = temp->next ; 
			}
		temp->next = ptr ; 
		ptr->next = head ; 
		head = ptr ; 	
	}
}
	
void insertBack(){
	struct node *ptr ; 
	ptr = malloc(sizeof(struct node)) ; 
	printf("ENTER THE ELEMENT TO BE INSERTED  : ") ; 
	scanf("%d" , &ptr->data) ;

	if(head == NULL){
		head = ptr ; 
		ptr->next = ptr ; 
	}
	else{
		struct node *temp ; 
		temp = head ; 
		while(temp->next != head){
			temp = temp->next ; 
		}
		temp->next = ptr ; 
		ptr->next = head ; 
	}
}	

void insertBetween(){
	struct node *ptr, *temp= head ;
	int i = 0 , pos ;  
	ptr = malloc(sizeof(struct node)) ; 
	
	printf("ENTER THE NUMBER TO BE INSERTED : ") ; 
	scanf("%d", &ptr->data) ; 
	
	printf("ENTER THE POSITION ON WHICH TO BE INSERTED  :") ; 
	scanf("%d" , &pos) ; 
	
	while(temp != head && i < pos-1){
		temp = temp->next ; 
		i++ ; 
		}
	if(temp == head){
		printf("INVALID POSITION\n") ; 

	}
	else{
		ptr->next = temp->next ; 
		temp->next = ptr ; 
	}
	}
	
	
void deleteFront(){
	if(head == NULL){
		printf("LIST IS EMPTY\n") ; 
		}
	else{
		struct node *temp = head ; 
		while(temp->next != head){
			temp = temp->next ; 
			}
		temp->next = head->next ; 
		free(head) ; 
		head = temp->next ; 	
	}
}

void deleteBack(){
	if(head == NULL){
		printf("LIST IS EMPTY\n") ; 
		}
	else{
		struct node *temp = head ; 
		while(temp->next->next != head){
			temp = temp->next ; 
			}
		free(temp->next) ; 
		temp->next = head ; 		
	}
} 

void search(){
	int key , flag = 0 ; 
	printf("ENTER THE ELEMENT TO BE SEARCHED : ") ; 
	scanf("%d" , &key) ; 
	struct node *ptr = head ; 
	while(ptr->next != head){
		if(ptr->data == key){
			flag = 1 ; 
			break ; 
			}
		ptr = ptr->next ; 
		}
	if(ptr->data == key){
		flag = 1 ; 
		}
	if(flag == 1){
		printf("ELEMENT FOUND\n") ; 
		}
	else{
		printf("ELEMENT NOT FOUND\n") ; 
		}
	}


void menu(){
	printf("1. CREATE\n") ; 
	printf("2. DISPLAY\n") ; 
	printf("3. INSERT AT FRONT\n") ; 
	printf("4. INSERT AT BACK\n") ; 
	printf("5. INSERT BETWEEN\n") ; 
	printf("6. DELETE FROM FRONT\n") ; 
	printf("7. DELETE FROM BACK\n") ; 
	printf("8. SEARCH\n") ; 
	printf("9. EXIT\n") ; 
}


int main(){
	int choice ; 
	while(1){
		menu() ; 
		printf("ENTER YOUR CHOICE : ") ; 
		scanf("%d" , &choice) ; 
		switch(choice){
			case 1 : 
				insertBack() ; 
				break ; 
			case 2 : 
				display() ; 
				break ; 
			case 3 : 
				insertFront() ; 
				break ; 
			case 4 : 
				insertBack() ; 
				break ; 
			case 5 : 
				insertBetween() ; 
				break ; 
			case 6 : 
				deleteFront() ; 
				break ; 
			case 7 : 
				deleteBack() ; 
				break ; 
			case 8 : 
				search() ; 
				break ; 
			case 9 : 
				exit(0) ; 
			default : 
				printf("INVALID CHOICE\n") ; 
		}
	}
	return 0 ;
}