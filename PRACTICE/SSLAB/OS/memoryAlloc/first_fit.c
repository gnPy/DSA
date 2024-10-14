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

void first_fit(){
    int occupy[p] ; 
    for( int i = 0 ; i < p ; i++){
        occupy[i] = -1 ; 
    }

    for( int i = 0 ; i < p ; i++){
        for( int j = 0 ; j < b ; j++){
            if(process[i]<= blocks[j]){
                blocks[j]-=process[i] ; 
                occupy[i] = j; 
                break ; 
            }
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
    first_fit() ; 
}

