//FIRST COME FIRST SERVE...
#include <stdio.h>
#include <stdlib.h>

struct details {
    int n; 
    int pos; 
} one; 

int requests[100]; 

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
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

void FCFS() {
    int seek = 0; 
    seek += abs_diff(one.pos, requests[0]); 
    for (int i = 0; i < one.n - 1; i++) {
        seek += abs_diff(requests[i], requests[i + 1]); 
    }
    
    printf("THE TOTAL HEAD MOVEMENT IS: %d\n", seek); 
}

int main() {
    input(); 
    FCFS(); 
    return 0;
}
