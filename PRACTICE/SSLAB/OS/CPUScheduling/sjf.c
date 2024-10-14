#include <stdio.h>

int main(){
    int n ; 
    printf("ENTER THE NUMBER OF PROCESSES : ") ; 
    scanf("%d" , &n) ; 

    int hash[100] = {0} ; 
    int at[100] ; 
    int bt[100] ; 
    int wt[100]  = {0} , wait = 0; 
    for( int i = 0 ; i< n ; ++i){
        printf("ENTER THE AT AND BT FOR THE PROCESS %d : " ,i) ; 
        scanf("%d %d" , &at[i] ,&bt[i]) ; 
    }

    int proc = 0 ; 
    int ct = 0 ; 
    while(proc < n ){
        int min = 9999 , index = -1 ; 
        for( int i = 0 ; i < n ; ++i){
            if(hash[i] == 0 && at[i] <= ct && bt[i] < min){
                min = bt[i] ; 
                index = i ; 
            }
        }
        if(index == -1){
            ct++ ; 
            continue ; 
        }
        
        hash[index]++ ; 
        wt[index] = ct - at[index] ; 
        ct += bt[index] ; 
        wait += wt[index] ; 
        proc++ ; 
        printf("PROCESS %d --> WAITING TIME %d\n" , index , wt[index]) ; 
    }
    printf("AVERAGE WAITING TIME IS %f\n" , (float)wait/n) ; 
}