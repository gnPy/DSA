#include <stdio.h>

int pow(int a , int b){
    if(b == 1){
        return a ; 
    }
    else{
        if(b % 2 == 0){
            return pow(a*a , b / 2) ; 
        }
        else{
            return b * pow(a*a , b / 2) ; 
        }
    }
}

int reverse(int n , int a){
    if(a == 1){
        return n ; 
    }
    return (n%10) * (int)pow(10 , a - 1) + reverse(n/10 , a - 1) ; 
}

int digits(int n){
    if(n == 0){
        return 0 ; 
    }
    return 1 + digits(n/10) ; 
}

int main(){
    for( int i = 1 ; i < 500 ; i++){
        printf("%d -- > %d\n" , i , reverse(i , digits(i))) ; 
    }
    printf("\n") ; 
}