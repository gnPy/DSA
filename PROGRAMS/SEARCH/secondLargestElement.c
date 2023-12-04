#include<stdio.h>

void swap(int *x , int *y){
    int temp = *x ; 
    *x = *y ; 
    *y = temp ; 
}

int bubbleSort(int *A , int n){
    int i , j , comp; 
    for(i = 0 ; i < 2 ; i++){
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
    return A[n-2] ; 
}

int main(){
    int n , i , x = 0 , m ;
    
    printf("ENTER THE NUMBER OF ELEMENTS : ") ; 
    scanf("%d" , &n) ; 

    int arr[n] ; 
    printf("ENTER ARRAY ELEMENTS : ") ; 
    for(i = 0 ; i < n ; i++){
        scanf("%d" , &arr[i]) ; 
    }    
    printf("SECOND LARGEST ELEMENT IS : %d\n" , bubbleSort(arr , n)) ;
}