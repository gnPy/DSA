//LFU...
#include <stdio.h>
#include <stdlib.h>

int requests[100] , freq[20] ; 

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

int min(int *req){
    int m = 20 ; 
    for( int i = 0 ; i < pages.slots ; i++){
        if(*(req+i) < m){
            m = *(req+i) ; 
        }
    }
    return m ; 
}

int element(int *req , int a){
    int priority[pages.slots] ; 
    for( int i = 0 ; i < pages.slots ; i++){
        priority[i] = freq[req[i]] ; 
    }

    int temp[pages.slots] ; 
    int index = 0 ; 
    for(int i = 0 ; i < pages.slots ; i++){
        if(priority[i] == min(priority)){
            temp[index++] = req[i] ;  
        }
    }
    for( int i = pages.slots - 1 ; i >= 0 ; i--){
        for( int j = 0 ; j < index ; j++){
            if(req[i] == temp[j]){
                return i ; 
            }
        }
    }

}

void LFU(){
    int faults = 0 ; 

    int slots[pages.slots] ; 
    for( int i = 0 ; i < pages.slots ; i++){
        slots[i] = -1 ; 
    }
    for( int i = 0 ; i < 20; i++){
        freq[i] = 0 ; 
    }

    for( int i = 0 ; i< pages.num ; i++){
        if(search(slots , pages.slots , requests[i]) == 1){
            freq[requests[i]]++ ; 
        }
        else{
            freq[requests[i]]++ ; 
            slots[element(slots , requests[i])] = requests[i] ; 
        }
        for( int j = 0 ; j < pages.slots ; j++){
            printf("%d  " , slots[j]) ; 
        }
        printf("\n") ; 
    }
    printf("TOTAL PAGE FAULTS  : %d" , faults) ; 
}

void main(){
    input() ; 
    LFU() ; 
}