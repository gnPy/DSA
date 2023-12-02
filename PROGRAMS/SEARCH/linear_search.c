#include <stdio.h>

int linearSearch(int *A ,int n ,  int x){
	for( int i = 0 ; i < n ; i++){
		if( A[i] == x){
			return i ; 
			}
		}
	return -1 ;
	}

int main(){
	int n , i , x ;
	printf("ENTER THE SIZE OF ARRAY : ") ;
	scanf("%d" , &n) ; 
	
	int arr[n] ; 
	printf("ENTER THE ARRAY ELEMENTS : ") ; 
	for(i = 0 ; i < n ; i++){
		scanf("%d" , &arr[i]) ; 
		}

	printf("ENTER THE ELEMENT TO BE SEARCHED : ") ; 
	scanf("%d" , &x) ;

	int index = linearSearch(arr, n , x) ;
	if( index == -1){
		printf("ELEMENT NOT FOUND.\n") ; 
		}
	else{
		printf("THE POSITION IS : %d\n" , index) ; 
		} 
	}
