#include <stdio.h>

int p , r , max[100][100] , alloc[100][100] , need[100][100] , available[100] , hash[100] ; 

void input(){
    printf("ENTER THE NUMBER OF PROCESSES  :") ; scanf("%d" , &p) ; 
    printf("ENTER THE NUMBER OF RESOURCE TYPES  :") ; scanf("%d" , &r) ; 

    //MAX
    printf("ENTER THE MAX MATRIX...\n") ; 
    for( int i = 0 ; i < p ; i++){
        printf("ENTER THE MAX RESOURCES FOR %d : " , i) ; 
        for( int j = 0 ; j < r ; j++){
            scanf("%d" , &max[i][j]) ; 
        }
    }

    //ALLOC
    printf("ENTER THE ALLOCATION MATRIX...\n") ; 
    for( int i = 0 ; i < p ; i++){
        printf("ENTER THE ALLOCATION MATRIX FOR %d : " , i) ; 
        for( int j = 0 ; j < r ; j++){
            scanf("%d" , &alloc[i][j]) ; 
        }
    }

    //NEED
    for( int i = 0 ;i < p ; i++){
        for( int j = 0 ; j < r ; j++){
            need[i][j] = max[i][j] - alloc[i][j]  ; 
        }
    }

    //AVAILABLE
    printf("ENTER THE AVAILABLE RESOURCES  : ") ; 
    for( int i = 0 ; i< r ; i++){
        scanf("%d" , &available[i]) ; 
    }
}

void bankers(){
    int found , flag  , count = 0; 

    for( int i = 0 ; i < p ; i++){
        hash[i] = 0 ; 
    }
    while( count < p){
        found = 0 ; 
        for( int i = 0 ; i < p ; i++){
            if(hash[i] == 0){
                flag = 0 ; 
                for( int j = 0 ; j < r ; j++){
                    if( available[j] < need[i][j]){
                        flag++ ; 
                        break ; 
                    }
                }
                if( flag == 0){
                    //RESOURCE ALLOCATION POSSIBLE...
                    found++ ; 
                    hash[i]++ ; 
                    count++ ; 
                    for( int j = 0 ; j < r ; j++){
                        available[j] += alloc[i][j] ;  
                    }

                    printf("%d -> " , i) ;
                }
            }
        }
        if(found == 0){
            printf("RESOURCE ALLOCATION NOT POSSIBLE.\n") ; 
            break ; 
        }
    }
    if( found != 0){
        printf("RESOURCE ALLOCATION POSSIBLE.\n") ; 
    }
}

void main(){
    input() ; 
    bankers() ; 
}