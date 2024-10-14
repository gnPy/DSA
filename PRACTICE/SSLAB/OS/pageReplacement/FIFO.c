//FIFO....
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

void FIFO(){
    int faults = 0 ; 

    int slot[pages.slots] ; 
    for( int i = 0 ; i< pages.slots ; i++){
        slot[i] = -1 ; 
    }

    for( int i = 0 ; i < pages.num ; i++){
        if(search(slot , pages.slots , requests[i]) == 1){
            continue ; 
        }
        else{
            push(slot , pages.slots ,requests[i]) ; 
            faults++ ; 
        }

        for( int j = 0 ; j < pages.slots ; j++){
            printf("%d " , slot[j]) ; 
        }
        printf("\n") ; 

    }
    printf("TOTAL PAGE FAULTS : %d\n" , faults) ; 
    printf("PAGE FAULT RATIO  : %lf\n" , ((float)faults/(float)pages.num)*100) ;
}

void main(){
    input() ; 
    FIFO() ; 
}