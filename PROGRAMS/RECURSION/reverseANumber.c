#include <stdio.h>

int reverse(int n){
    if( n < 10){
        return n ; 
    }
    else{
        return (n%10) * 10 + reverse(n/10) ; 
    }    
}

int main(){
    for( int i = 1 ; i < 100 ; i++){
        printf("%d -- > %d\n" , i , reverse(i)) ; 
    }
    printf("\n") ; 
}