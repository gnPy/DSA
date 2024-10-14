#include <stdio.h>

int main(){
    int n ; 
    printf("ENTER THE NUMBER OF PROCESSES : ") ; 
    scanf("%d" , &n) ; 

    int bt[100] ; 
    int at[100] ; 
    int prio[100] ; 
    int hash[100] ={0} ; 
    int wait[100] = {0} , wt = 0; 
    for( int i = 0 ; i< n ; ++i){
        printf("ENTER THE AT BT PRIO FOR PROCESS %d : " , i) ; 
        scanf("%d %d %d" , &at[i] , &bt[i] , &prio[i]) ; 
    }

    int proc= 0 ; 
    int ct = 0 ; 
    while(proc < n){
        int min = 9999 , index = -1 ; 
        for( int i = 0 ; i < n ; ++i){
            if(hash[i] == 0 && at[i] <= ct && prio[i]<min){
                min = prio[i] ; 
                index = i  ; 
            }
        }
        if( index == -1){
            ct++ ; 
            continue;
        }
        proc++ ; 
        wait[index] = ct - at[index] ; 
        wt += wait[index] ; 
        ct += bt[index] ; 
        hash[index]++ ; 
        printf("PROCESS %d --> WAITING TIME %d\n" , index , wait[index]) ; 
    }
    printf("AVERAGE WAITING TIME IS %f\n" , (float)wt/n) ; 
    
}