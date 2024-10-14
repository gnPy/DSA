#include <stdio.h>
#include <stdlib.h>

int main(){
    int n ; 
    printf("ENTER THE NUMBER OF FILES : ") ; 
    scanf("%d" , &n) ; 

    int disk[1000] = {0}; 
    int start[100] ; 
    int blocks[100] ; 
    for(int i = 0 ; i< n ; ++i){
        printf("ENTER THE NO.OF BLOCKS OF %d : ", i) ; 
        scanf("%d" , &blocks[i]) ; 
        printf("ENTER THE BLOCKS TO BE ALLOCATED : ") ; 
        int bl ; 
        scanf("%d" , &bl) ; 
        if(disk[bl] == 0){
            start[i] = bl ; 
            for(int j = 0 ; j < blocks[i] - 1 ; ++j){
                int temp ; 
                scanf("%d" , &temp) ; 
                if(disk[temp] == 0){
                    disk[bl] = temp ; 
                    bl = temp ; 
                }
                else{
                    printf("BLOCK ALREADY TAKEN.\n") ; 
                    break ; 
                    --i ; 
                }
            }
            disk[bl] = -1 ; 
        }
        else{
            printf("BLOCK ALREADY TAKEN.\n") ; 
            i-- ; 
        }

    }
    //PRINTING
    printf("FILE\tBLOCKS\n") ; 
    for(int i = 0 ; i < n ; ++i){
        printf("%d\t" , i) ; 
        int temp = start[i] ; 
        for(int j = 0 ; j < n ; ++j){
            printf("%d " , temp) ; 
            temp = disk[temp] ; 
        }
        printf("\n") ; 
    }
}