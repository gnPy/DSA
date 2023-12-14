#include <stdio.h>
#include <stdlib.h>

struct node {
	int data ; 
	struct node *next ; 
	}*head = NULL ; 

void create(){
	struct node *temp ; 
 
	int n ; 
	printf("ENTER THE NUMBER OF ELEMENTS  : ") ; 
	scanf("%d" , &n) ; 
	
	printf("ENTER THE ELEMENTS : ") ;  
	for ( int i = 0 ; i< n ; i++){
		struct node *ptr ; 
		ptr = malloc(sizeof(struct node)) ;

		scanf("%d" ,&ptr->data) ; 
		if(i==0){
			head = ptr ;
			ptr->next =NULL ;  
			temp = ptr ; 
			}
		else{
			temp->next = ptr ; 
			ptr->next =NULL ; 
			temp = ptr ; 
			}
		
		}
	}

void display(){
	struct node *ptr ; 
	ptr = head ; 
	while(ptr!= NULL){
		printf("%d " , ptr->data) ; 
		ptr = ptr->next ; 
		}
	printf("\n") ; 
	}

void insertFront(){
	struct node *ptr ;
	ptr = malloc(sizeof(struct node)) ;  
	printf("ENTER THE ELEMENT TO BE INSERTED : ") ; 
	scanf("%d" , &ptr->data) ;
	
	ptr->next = head ;
	head = ptr ; 
	} 
	
void insertBack(){
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

void insertBetween(){
	struct node *ptr, *temp= head ;
	int i = 0 , pos ;  
	ptr = malloc(sizeof(struct node)) ; 
	
	printf("ENTER THE NUMBER TO BE INSERTED : ") ; 
	scanf("%d", &ptr->data) ; 
	
	printf("ENTER THE POSITION ON WHICH TO BE INSERTED  :") ; 
	scanf("%d" , &pos) ; 
	
	while(temp != NULL && i < pos-1){
		temp = temp->next ; 
		i++ ; 
		}
	if(temp == NULL){
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
		struct node *temp= head ; 
		head = head->next ; 
		free(temp);  
	}
}

void deleteBack(){
	if(head == NULL){
		printf("LIST IS EMPTY\n") ; 
		}
	else if(head->next == NULL){
		free(head) ;
		head = NULL ; 
		}
	else{
		struct node *temp = head ; 
		while(temp->next->next != NULL){
			temp = temp->next ; 
			}
		free(temp->next) ; 
		temp->next = NULL ; 
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
	printf("4. INSERT AT BACK\n") ; 
	printf("5. INSERT BETWEEN\n") ; 
	printf("6. DELETE FRONT\n") ; 
	printf("7. DELETE BACK\n") ; 
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
			case 4 : insertBack() ; 
				 break ; 
			case 5 : insertBetween() ; 
				 break ; 
			case 6 : deleteFront() ; 
				 break ; 
			case 7 : deleteBack() ; 
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