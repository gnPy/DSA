#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swap(char *a , char *b){
    char temp = *a ; 
    *a = *b ; 
    *b = temp ; 
}

void permute(char *a , int first , int last){
    if( first == last){
        printf("%s\t" , a) ; 
    }
    else{
        for( int j = first ; j <= last ; ++j){
            swap((a+first) , (a+j)) ; 
            permute(a , first+1 , last) ; 
            swap((a+first) , (a+j)) ; //BACKTRACK
        }
    }
}

void main(){
    char *s = malloc(100*sizeof(char)); 
    strcpy(s , "ABC") ; 
    permute(s , 0 , 2) ; 
    printf("\n") ; 
}