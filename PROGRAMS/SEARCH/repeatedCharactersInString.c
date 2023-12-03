#include<stdio.h>
#include <string.h>

int main(){
    int ascii[129] = {0} ; 
    
    char str[1000] ; 
    printf("ENTER THE STRING  :") ; 
    fgets(str , 1000 , stdin) ;  

    for( int i = 0 ; i < strlen(str) ; i++){
        ascii[(int)str[i]]++ ; 
    }

    printf("REPEATED ELEMENTS ARE : \n") ; 
    for( int i = 0 ; i < 129 ; i++){
        if(ascii[i] > 1 && i != 32 ){
            printf("%c - %d\n" , i , ascii[i]) ; 
        }
    }  
}