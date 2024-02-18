#include <stdio.h>

int sumOfDigits(int n){
    if( n >0){
        return n%10 + sumOfDigits(n/10) ; 
    }
    return 0 ; 
}

int main(){
    for( int i = 0 ; i< 25  ; i++){
        printf("%d = %d\n" , i , sumOfDigits(i)); 
    }
    printf("\n") ;
}