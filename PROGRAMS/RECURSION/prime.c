#include <stdio.h>

int prime(int n , int i){
    if(i > 1){
        if(n %i == 0){
            return 0 ; 
        }
        else{
            return prime(n , i-1) ; 
        }
    }
    return 1 ; 
}

int main(){
    for( int i = 2 ; i < 100 ; i++){
        int x=prime(i,i-1) ; 
        if(x == 1){
            printf("%d ", i) ; 
        }
    }
    printf("\n") ; 
}