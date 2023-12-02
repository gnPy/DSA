#include <stdio.h>

int binarySearch(int *A , int l , int h , int x){
	if(l<=h){
		int mid = (l+h)/2 ; 
		if( A[mid] == x){
			return mid ; 
			}
		else if(A[mid] > x){
			return binarySearch(A ,l , mid-1 ,x) ; 
			}
		else{
			return binarySearch(A ,mid+1 , h , x) ; 
			}
		}
	return -1 ; 
	}

int main(){
	int n , i , x ;
	printf("ENTER THE SIZE OF ARRAY  : ") ;
	scanf("%d" , &n) ; 
	
	int arr[n] ; 
	printf("ENTER THE ARRAY ELEMENTS : ") ; 
	for(i = 0 ; i < n ; i++){
		scanf("%d" , &arr[i]) ; 
		}

	printf("ENTER THE ELEMENT TO BE SEARCHED : ") ; 
	scanf("%d" , &x) ;

	int index = binarySearch(arr, 0 ,  n-1 , x) ;
	if( index == -1){
		printf("ELEMENT NOT FOUND.\n") ; 
		}
	else{
		printf("THE POSITION IS : %d\n" , index) ; 
		} 
	}
