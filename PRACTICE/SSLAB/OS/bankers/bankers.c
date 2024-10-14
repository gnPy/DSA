#include<stdio.h>

int main(){
    int max[100][100], alloc[100][100], need[100][100], available[100]; 
    int n, r; 
    printf("ENTER THE NUMBER OF PROCESSES AND NUMBER OF RESOURCE TYPES: "); 
    scanf("%d %d", &n, &r); 

    //INPUTTING MAX MATRIX
    printf("ENTER THE MAX MATRIX.\n"); 
    for(int i = 0; i < n; ++i){
        printf("ENTER THE MAX RESOURCES FOR PROCESS %d: ", i); 
        for(int j = 0; j < r; ++j){
            scanf("%d", &max[i][j]); 
        }
    }

    //INPUTTING ALLOC MATRIX
    printf("ENTER THE ALLOC MATRIX.\n"); 
    for(int i = 0; i < n; ++i){
        printf("ENTER THE ALLOC RESOURCES FOR PROCESS %d: ", i); 
        for(int j = 0; j < r; ++j){
            scanf("%d", &alloc[i][j]); 
        }
    }

    //CALCULATING NEED MATRIX
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < r; ++j){
            need[i][j] = max[i][j] - alloc[i][j]; 
        }
    }

    //INPUTTING AVAILABLE RESOURCES
    printf("ENTER AVAILABLE RESOURCES: "); 
    for(int i = 0; i < r; ++i){
        scanf("%d", &available[i]);     
    }

    //BANKERS LOGIC...
    int hash[100] = {0} , count = 0 , flag , found ; 
    while(count < n){
        found = 0 ;
        for(int i = 0 ; i < n ; ++i){
            if(hash[i] == 0){
                flag = 1 ; 
                for(int j = 0 ; j < r ; ++j){
                    if(available[j] < need[i][j]){
                        flag = 0 ; 
                        break ; 
                    }
                }
            
                if(flag == 1){
                    //possible
                    found++ ; 
                    count++ ; 
                    hash[i]++ ; 
                    for(int j = 0 ; j < r ; ++j){
                        available[j] += alloc[i][j] ; 
                    }
                    printf("%d --> " , i) ; 
                }
            }
        } 
        if(found == 0){
            printf("RESOURCE ALLOCATION NOT POSSIBLE.\n") ; 
            break ; 
        }

    }
    if(count == n){
        printf("RESOURCE ALLOCATION POSSIBLE.\n") ; 
    }
    

    return 0;
}
