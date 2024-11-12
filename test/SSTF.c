//SHORTEST SEEK TIME FIRST...
#include <stdio.h>
#include <stdlib.h>

struct details {
    int n; 
    int pos; 
} one; 

int requests[100]; 

int abs_diff(int a , int b){
    return (a>b)? (a-b): (b-a) ; 
}

void input() {
    printf("ENTER THE CURRENT POSITION OF THE POINTER: "); 
    scanf("%d", &one.pos); 
    printf("ENTER THE NUMBER OF REQUESTS: "); 
    scanf("%d", &one.n); 
    printf("ENTER THE REQUESTS: "); 
    for (int i = 0; i < one.n; i++) {
        scanf("%d", &requests[i]); 
    }
}

int find_closest(int n){
    int index = -1 ; 
    int value = 10000 ; 
    for( int i = 0 ; i < one.n ; i++){
        if(abs_diff(requests[i] , n)< value && requests[i] != -1){
            index = i ; 
            value = abs_diff(requests[i] , n) ; 
        }
    }
    return index ; 
}

void SSTF(){
    int seek = 0 ; 
    int current_pos = one.pos ; 
    for( int i = 0 ; i < one.n ; i++){
        int close = find_closest(current_pos) ; 
        seek+= abs_diff(requests[close] , current_pos) ; 
        current_pos = requests[close] ; 
        requests[close] = -1 ; 
        //TEST
        for (int j = 0; j < one.n; j++) {
            printf("%d ", requests[j]); 
        }
        printf("\n");
    }
    printf("THE TOTAL HEAD MOVEMENT IS : %d\n" , seek) ; 
}

void main(){
    input() ; 
    SSTF() ; 
}