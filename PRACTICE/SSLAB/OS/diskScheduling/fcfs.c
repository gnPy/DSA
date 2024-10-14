#include <stdio.h>
#include <stdlib.h>
int main(){
    int n , p; 
    int requests[100] ; 
    printf("ENTER THE CURRENT POINTER AND NO.OF REQUESTS : ") ; 
    scanf("%d %d" , &p , &n) ; 
    int movement = 0 ; 
    printf("ENTER THE REQUESTS : ") ;
    for(int i = 0 ; i < n ; ++i){
        scanf("%d" , &requests[i]) ; 
        movement += abs(requests[i] - p) ; 
        p = requests[i] ; 
    }

    for(int i = 0 ; i < n ; ++i){
        printf("%d --> " , requests[i]) ; 
    }
    printf("\n") ; 
    printf("TOTAL HEAD MOVEMENT IS  : %d\n" , movement) ; 
}