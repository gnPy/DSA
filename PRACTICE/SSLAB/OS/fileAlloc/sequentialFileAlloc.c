#include <stdio.h>

int main(){
    int disk[1000] = {0} ; 
    int start[100] ; 
    int blocks[100] ; 
    int n ; 
    printf("ENTER THE NUMBER OF FILES : ") ; 
    scanf("%d" , &n) ; 
    
    for( int i = 0 ; i< n ; ++i){
        printf("ENTER THE SA AND NO.OF BLOCKS OF %d : " , i) ; 
        scanf("%d %d" , &start[i] , &blocks[i]) ; 
        for(int j = start[i] ; j < start[i] + blocks[i] ; ++j){
            if(disk[j] == 1){
                printf("THIS FILE CANNOT BE CREATED.\n") ; 
                i-- ; 
                break ; 
            }
            else{
                disk[j]++ ; 
            }
        }
    }
    printf("FILE\tSA\tBLOCKS\n") ; 
    for(int i = 0 ; i < n ; ++i){
        printf("%d\t%d\t" , i , start[i]) ; 
        for(int j = start[i] ; j < start[i] + blocks[i] ; ++j){
            printf("%d " , j) ; 
        }
        printf("\n") ; 
    }

}