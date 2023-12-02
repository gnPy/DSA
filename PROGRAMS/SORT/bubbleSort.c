#include<stdio.h>

void swap(int *x , int *y){
    int temp = *x ; 
    *x = *y ; 
    *y = temp ; 
}

void bubbleSort(int *A , int n){
    int i , j , comp; 
    for(i = 0 ; i < n ; i++){
        comp = 0 ;  
        for(j = 0 ; j < n-i-1 ; j++){
            if(A[j]>A[j+1]){
                swap(&A[j] , &A[j+1]) ; 
                comp++ ; 
            }
        }
        if(comp == 0){
            break ; 
        }
    }
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

    bubbleSort(arr, n );
    
    printf("THR SORTED ARRAY IS : ") ; 
    for(i = 0 ; i < n ; i++){
        printf("%d " , arr[i]) ; 
        }
    printf("\n") ; 
	}
