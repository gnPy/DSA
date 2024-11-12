#include <stdio.h>
#include <stdlib.h>

int blocks[100] , process[100] , p , b ;

void input(){
    printf("ENTER THE NUMBER OF PROCESSES : ") ; 
    scanf("%d" , &p) ; 
    printf("ENTER THE SIZES OF THE PROCESSES : ") ; 
    for( int i = 0 ; i < p ; i++){
        scanf("%d" , &process[i]) ; 
    }

    printf("ENTER THE NUMBER OF MEMORY BLOCKS : ") ; 
    scanf("%d" , &b) ; 
    printf("ENTER THE SIZES OF MEMORY BLOCKS : ") ; 
    for( int i = 0 ; i < b; i++){
        scanf("%d" , &blocks[i]) ; 
    }
}

int find_min(int proc){
    int min = 10000 ; 
    int index = -1 ; 
    for( int i = 0 ; i < b ; i++){
        if(blocks[i]>=proc && blocks[i] < min){
            index = i ; 
            min = blocks[i] ; 
        }
    }
    return index ; 
}

void best_fit(){
    int occupy[p] ; 
    for( int i = 0 ; i < p ; i++){
        occupy[i] = -1  ; 
    }

    for( int i = 0 ; i < p ; i++){
        int temp = find_min(process[i]) ; 
        if(temp != -1){
            occupy[i] = temp ;
            blocks[temp] -= process[i] ; 
        }
    }

    for( int i = 0 ; i < p ; i++){
        if(occupy[i] != -1){
            printf("PROCESS %d IS ALLOCATED BLOCK %d\n" , i , occupy[i]) ; 
        }
        else{   
            printf("PROCESS %d IS NOT ALLOCATED ANY BLOCKS.\n" , i) ; 
        }
    }

    for( int i = 0 ; i <b ; i++){
        printf("%d-" , blocks[i]) ; 
    }
    printf("\n") ; 

}

void main(){
    input() ; 
    best_fit() ; 
}


