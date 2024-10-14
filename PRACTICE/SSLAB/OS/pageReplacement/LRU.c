//LRU...
#include <stdio.h>
#include <stdlib.h>

int requests[100] ; 

struct details{
    int num ; 
    int slots ; 
    
}pages ; 

void input(){
    printf("ENTER THE PAGE SLOTS : ") ; 
    scanf("%d" , &pages.slots) ; 
    printf("ENTER THE NUMBER OF PAGES : ") ; 
    scanf("%d" , &pages.num) ; 
    printf("ENTER THE PAGES : ") ; 
    for( int i = 0 ; i < pages.num ; i++){
        scanf("%d" , &requests[i]) ; 
    }
}

void push(int *req , int n , int a){
    for( int i = n-1 ; i>0 ; i--){
        *(req+i) = *(req+i-1) ; 
    }
    *(req) = a ; 
}

int search(int *req , int n , int a){
    for( int i = 0 ; i< n ; i++){
        if(*(req+i) == a){
            return 1 ; 
        }
    }
    return 0 ; 
}

void swap(int *req , int a){
    int index = pages.slots-1 ; 
    while(*(req + index) != a){
        index-- ;
    }

    int temp = *(req + index) ; 

    while( index > 0){
        *(req+index) = *(req + index - 1) ; 
        index-- ; 
    }
    *req = temp ; 
}

void LRU(){
    int faults = 0 ; 

    int slots[pages.slots] ; 
    for( int i = 0 ; i < pages.slots ; i++){
        slots[i] = -1 ; 
    }

    for( int i = 0 ; i < pages.num ; i++){
        if(search(slots , pages.slots , requests[i]) == 0){
            faults++ ; 
            push(slots , pages.slots , requests[i]) ; 
        }
        else{
            swap(slots , requests[i]) ; 
        }

        for(  int j = 0 ; j < pages.slots ; j++){
            printf("%d " , slots[j]) ; 
        }
        printf("\n") ; 
    }
    printf("NUMBER OF PAGE FAULTS IS  : %d\n" , faults) ; 
}

void main(){
    input() ; 
    LRU() ; 
}
