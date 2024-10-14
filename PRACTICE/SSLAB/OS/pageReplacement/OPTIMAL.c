//OPTIMAL....
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

int search(int *req , int n , int a){
    for( int i = 0 ; i< n ; i++){
        if(*(req+i) == a){
            return 1 ; 
        }
    }
    return 0 ; 
}

int next(int *slot , int *req , int a){
    int temp[pages.slots] ; 
    for( int i = 0 ; i < pages.slots ; i++){
        temp[i] = pages.num ; 
    }

    for( int i = 0 ; i < pages.slots ; i++){
        for( int j = a+1 ; j < pages.num ; j++){
            if(*(req+j) == *(slot+i)){
                temp[i] = j-a ; 
                break ; 
            }
        }
    }
    int index = 0 ; 
    int max = -1 ; 
    for( int i = 0 ; i < pages.slots ; i++){
        if( temp[i] > max){
            index = i ; 
            max = temp[i] ; 
        }
    }
    return index ; 
}

void OPTIMAL(){
    int faults = 0;      
    int slots[pages.slots] ; 

    for( int i = 0 ; i < pages.slots ; i++){
        slots[i] = -1 ; 
    }

    for( int i = 0 ; i < pages.num ; i++){
        if(i < pages.slots){
            slots[i] = requests[i] ; 
            faults++ ;  
        }
        else{
            if(search(slots , pages.slots , requests[i]) == 1){
                continue ; 
            }
            else{
                int index = next(slots , requests, i) ; 
                slots[index] = requests[i] ; 
                faults++ ; 
            }
        }
        
        //TEST
        for( int i = 0 ; i < pages.slots ; i++){
            printf("%d " , slots[i]) ;
        }
        printf("\n") ; 
    }
    printf("TOTAL PAGE FAULTS : %d\n" , faults) ; 
}

void main(){
    input() ; 
    OPTIMAL() ;     
}