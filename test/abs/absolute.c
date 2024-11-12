#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input = fopen("input.txt" , "r") ; 
    char type , line[100]  ; 
    int start_addr , load_addr ; 

    fscanf(input , "%s" , line) ; 
    if(line[0] == 'H'){
        char name[20] , addr[20] ;
        int i = 2 , j= 0 ; 
        while(line[i] != '^'){
            name[j++] = line[i++] ; 
        } 
        name[j] = '\0' ; 
        i++ ;
        for(j = 0 ; j < 4 ; ++j){
            addr[j] = line[i++] ; 
        }
        start_addr = strtol(addr, NULL , 16) ;         
        printf("THE NAME OF THE FILE IS : %s\n" , name) ; 
        printf("THE STARTING ADDERSS IS : %04X\n" , start_addr) ; 
    }
    while(feof(input) == 0){
        fscanf(input , "%s" , line) ; 
        if(line[0] == 'T'){
            char load[5] ; 
            for(int i = 0 ; i < 4 ; ++i){
                load[i] = line[i+2] ; 
            }
            load_addr = strtol(load , NULL  , 16) ;
            printf("THE STARTING ADDRESS OF TEXT RECORD IS : %04X\n" , load_addr) ; 

            int i = 10 ; 
            while(line[i] != '\0'){
                if(line[i] == '^'){
                    i++ ; 
                }
                else{
                    printf("ADDDRESS %04X : %c%c\n" , load_addr++ , line[i] , line[i+1]) ; 
                    i += 2 ; 
                }
            }
        }
        else if(line[0] == 'E'){
            break ; 
        }        
    }
    printf("THE EXECUTION ADDRESS IS : %04X\n" , start_addr) ; 
    fclose(input) ; 
}