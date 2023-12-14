#include <stdio.h>

int merge(int A[] , int low , int mid , int high){
	int n1 = mid-low+1 ; 
	int n2 = high - mid ; 

	int arr1[n1] ; 
	int arr2[n2] ; 
	
	for(int i = 0 ; i< n1 ; i++) arr1[i] = A[low + i] ; 
	for( int i = 0 ; i < n2 ; i++) arr2[i] = A[mid + i +1] ; 
	
	while(

int mergesort(int A[] , int low , int high){
	if(low<high){
		int mid = (low+high)/2 ; 
		mergesort(A , low , mid) ; 
		mergesort(A , mid+1 , high) ; 
		merge(A , low , mid , high) ; 
		}
	}








int main(){
	int arr[] = {5,4,3,2,1} ; 
	mergesort(arr , 0 , 4) ; 
	for( int i = 0 ; i  < 5 ; i++){
		printf("%d ", arr[i]) ; 
		}
	}

