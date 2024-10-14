#include <stdio.h>

int main(){
    int n, tq; 
    printf("ENTER THE NUMBER OF PROCESSES AND TIME QUANTA: "); 
    scanf("%d %d", &n, &tq); 

    int hash[100] = {0}; 
    int wait[100] = {0}; 
    int bt[100]; 
    int btCopy[100] ; 

    for (int i = 0; i < n; ++i) {
        printf("ENTER THE BT OF PROCESS %d: ", i); 
        scanf("%d", &bt[i]); 
        btCopy[i] = bt[i] ; 
    }

    int proc = 0;
    int ct = 0; 

    while (proc < n) {
        for (int i = 0; i < n; ++i) {
            if (hash[i] == 0) {
                if (bt[i] > tq) {
                    ct += tq; 
                    bt[i] -= tq; 
                } 
                else {
                    ct += bt[i]; 
                    bt[i] = 0;  
                    hash[i] = 1; 
                    proc++; 
                    wait[i] = ct - btCopy[i] ; 
                    printf("PROCESS %d --> WAITING TIME %d\n" , i , wait[i]) ; 
                    
                }
            }
        }
    }

    return 0;
}
