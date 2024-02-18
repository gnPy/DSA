#include <stdio.h>

int binToDec(int n){
    if( n > 0){
        static int i = 1; 
        i*=2 ; 
        return (n%10) * i + binToDec(n/10) ;       
    }
    return 0 ; 
}

int main(){
    printf("%d \n" , binToDec(101)/2) ; 
}