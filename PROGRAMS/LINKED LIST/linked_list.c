#include <stdio.h>
#include <stdlib.h>

struct node {
	int data ; 
	struct node *next ; 
	}*head;

void create(int n, int arr[]){
	struct node *now , *first ; 

	first = malloc(sizeof(struct node)) ; 
	first->data = arr[0] ; 
	first->next = NULL ; 
	now = first ;
	head = first ;  

	for( int i = 1 ; i< n ; i++){
		struct node *ptr ; 
		ptr = malloc(sizeof(struct node)) ; 
		ptr->data = arr[i] ;  
		ptr->next = NULL ; 
		now->next = ptr ;
		now = ptr ; 
		}

	}
	
void insert_begin(int a){
	struct node *ptr ; 
	ptr =malloc(sizeof(struct node)) ; 
	ptr->data = a ; 
	ptr->next = head ; 
	head = ptr ; 
	}

void insert_end(int a){
	struct node *ptr ; 
	ptr = malloc(sizeof(struct node)) ; 
	ptr = head ;
	while(ptr != NULL && ptr->next != NULL){
		ptr = ptr->next ; 
		}

	struct node *last ; 
	last = malloc(sizeof(struct node)) ; 
	ptr->next = last ; 
	last->next = NULL ; 
	last->data =a ; 
	}

void insert_between(int x , int pos){
	struct node *ptr ; 
	ptr =head; 
	int i = 1 ; 
	while(ptr!=NULL && i < pos){
		i++;
		ptr = ptr->next ; 
		}

	struct node *bet ;
	bet = malloc(sizeof(struct node)) ; 
	bet->data = x ; 
	bet->next = ptr->next ; 
	ptr->next = bet ; 
	}

void delete_front(){
	struct node *ptr ; 
	ptr = head ; 
	head = ptr->next ;
	free(ptr) ;   
	}
 
void delete_end(){
	struct node *ptr ; 
	ptr = head ; 
	while(ptr->next->next != NULL){
		ptr = ptr->next ; 
		}
	free(ptr->next) ; 
	ptr->next = NULL ;  
	}

void search(int x){
	struct node *ptr ; 
	ptr = head ; 
	int i = 1 ; 
	while(ptr!= NULL){
		if(ptr->data == x){
			printf("NODE NUMBER : %d\n" , i) ;
			break ;  
			}
		i++ ;
		ptr = ptr->next ;  
		}
	if( ptr == NULL){
		printf("ELEMENT NOT FOUND.\n") ; 
		}
	}

void display(){
	struct node *ptr ; 
	ptr = head ; 
	while(ptr){
		printf("%d " , ptr->data) ;
		ptr =ptr->next ;  
		}
	printf("\n") ; 
	}

int main(){
	head = NULL ; 	
	int ch = 1  , n , x , pos;
	int arr[n] ; 
	
	while(ch){ 
		printf("MENU\n") ; 
		printf("1  : DISPLAY.\n") ; 
		printf("2  : CREATE.\n") ; 
		printf("3  : INSERT AT FRONT.\n") ; 
		printf("4  : INSERT AT END.\n") ; 
		printf("5  : INSERT AFTER N-TH POS.\n") ; 
		printf("6  : DELETE AT FRONT.\n" ) ; 
		printf("7  : DELETE AT END.\n") ; 
		printf("8  : SEARCH AN ELEMENT.\n") ; 
		printf("9  : DELETE AN ELEMENT.\n") ;
		printf("0 : EXIT.\n") ;  
		printf("ENTER THE CHOICE : ") ; 
		scanf("%d" , &ch) ; 
		
		switch(ch){
			case 1:
				display() ; 
				break ; 
		
			case 2:

				printf("ENTER NUMBER OF ELEMENTS : ") ; 
				scanf("%d" , &n) ; 

				printf("ENTER THE ELEMENTS : ") ; 
				for( int i = 0 ; i < n ; i++){
					scanf("%d" ,&arr[i]) ; 
					}
				create(n , arr) ; 
				break ;
	 
			case 3:

				printf("ENTER THE ELEMENT TO BE INSERTED : ") ; 
				scanf("%d" , &x) ; 
				insert_begin(x) ; 
				break ;
	 
			case 4: 

				printf("ENTER THE ELEMENT TO BE INSERTED : ") ; 
				scanf("%d" , &x) ; 
				insert_end(x) ; 
				break ; 
			
			case 5: 

				printf("ENTER THE ELEMENT AS WELL AS POS AFTER WHICH TO BE INSERTED : ") ; 
				scanf("%d %d" , &x , &pos) ; 
				insert_between(x , pos) ; 
				break ; 
			
			case 6:
				delete_front() ; 
				break ; 
		
			case 7:
				delete_end() ; 
				break ; 
			
			case 8:

				printf("ENTER ELEMENT TO BE SEARCHED : ") ; 
				scanf("%d" , &x) ; 
				search(x) ; 
				break ; 
			
			case 0:
				printf("THANK YOU.\n") ; 
				break ; 
			
			default:
				printf("WRONG CHOICE.\n" ) ; 
				break ;  
				
			}
		printf("\n") ; 
		}
	}

