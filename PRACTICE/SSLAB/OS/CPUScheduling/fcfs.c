#include <stdio.h>

int main(){
    int n ; 
    printf("ENTER THE NUMBER OF PROCESSES : ") ; 
    scanf("%d" , &n) ; 
    int pro[100] ; 
    for( int i = 0 ; i < n ; ++i){
        printf("ENTER THE BURST TIME FOR THE PROCESS %d : " , i) ; 
        scanf("%d" , &pro[i]) ; 
    }
    printf("\n") ; 
    int wait[100]  , wt = 0, ct = 0;
    for(int i = 0 ; i< n ; ++i){
        wait[i] = ct ; 
        wt += ct ; 
        ct += pro[i] ;
        printf("PROCESS %d --> WAITING TIME %d\n" , i , wait[i]) ; 
    } 
    printf("AVERAGE WAITING TIME IS %f\n" , (float)wt/n) ; 
}