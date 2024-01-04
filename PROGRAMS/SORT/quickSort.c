#include <stdio.h>

void swap(int *a , int *b){
	int temp = *b ;
	*b = *a ; 
	*a = temp ; 
	} 

int partition(int A[] , int low, int high){
	int pivot = A[low] , i = low , j = high ;
	while(i<j){
		while(A[i] <= pivot){
			i++ ; 
			}
		while(A[j] > pivot){
			j-- ; 
			}
		if(i<j){
			swap(&A[i] ,&A[j]) ; 
			}
		}
	swap(&A[low] ,&A[j]) ;
	return j ;  
	}

void quicksort(int A[] , int low , int high){
	if(low<high){
		int pivot = partition(A , low , high) ; 
		quicksort(A , low , pivot-1) ; 
		quicksort(A , pivot+1 , high) ; 
		}
	}

int main(){
	int n ; 
	printf("ENTER THE NUMBER OF ELEMENTS : ") ;
	scanf("%d" , &n) ;
	int A[n] ;
	printf("ENTER THE ELEMENTS : ") ;
	for(int i = 0 ; i<n ; i++){
		scanf("%d" , &A[i]) ; 
		}
	quicksort(A , 0 , n-1) ;
	printf("THE SORTED ARRAY IS : ") ;
	for(int i = 0 ; i<n ; i++){
		printf("%d " , A[i]) ; 
		}
	printf("\n") ;
	}

