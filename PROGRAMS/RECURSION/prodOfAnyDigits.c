#include <stdio.h>

int prodOfDigits(int n){
    if( n >0){
        return n%10 * prodOfDigits(n/10) ; 
    }
    return 1 ; 
}

int main(){
    for( int i = 1 ; i< 25  ; i++){
        printf("%d = %d\n" , i , prodOfDigits(i)); 
    }
    printf("\n") ;
}