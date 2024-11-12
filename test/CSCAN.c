//CIRCULR SCAN...
#include <stdio.h>
#include <stdlib.h>

struct details {
    int n; 
    int disc; 
    int dir ; 
    int pos ; 
} one; 

int requests[100]; 

int find_extreme(int d){
    int m ; 
    if(d == 1){
        m = 0 ; 
        for(int i = 0 ; i< one.n ; i++){
            if(requests[i] > m && requests[i] < one.pos){
                m = requests[i] ; 
            }
        }
    }
    else{
        m = one.disc ; 
        for(int i = 0  ;i < one.n ; i++){
            if(requests[i] < m && requests[i] > one.pos){
                m = requests[i] ; 
            }
        } 
    }
    return m ; 
}

int input(){
    printf("ENTER THE NUMBER OF REQUESTS : ") ; 
    scanf("%d" , &one.n) ; 

    printf("ENTER THE REQUESTS : ") ; 
    for( int i = 0 ; i < one.n ; i++){
        scanf("%d" , &requests[i]) ; 
    }
    
    printf("ENTER THE CURRENT POSITION : ") ; 
    scanf("%d" , &one.pos) ; 
    printf("ENTER THE DISK SPACE : ") ; 
    scanf("%d" , &one.disc) ; 
    printf("DO U WANT TO TRAVERSE UPWARDS : ") ; 
    scanf("%d" , &one.dir) ;     
}

void CSCAN(){
    int seek = 0 ; 
    if(one.dir == 1){
        seek += one.disc - one.pos ; 
        seek += one.disc ; 
        seek += find_extreme(one.dir) ; 
    }
    else{
        seek += one.pos;  
        seek += one.disc ; 
        seek += one.disc - find_extreme(one.dir) ; 
    }

    printf("TOTAL HEAD MOVEMENT IS : %d\n" , seek) ; 
}

void main(){
    input() ; 
    CSCAN() ; 
}


