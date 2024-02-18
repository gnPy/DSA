#include <stdio.h>

int count(int n){
    if( n > 0){
        return 1 + count( n/10 ) ; 
    }
    return 0 ; 
}

int main(){
    for( int i = 1 ; i < 25 ; i++){
        printf("%d --> %d\n" , i , count(i)) ; 
    }
    printf("\n") ; 
}