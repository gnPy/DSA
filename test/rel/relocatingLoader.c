#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int start_addr ; 
	printf("ENTER THE STARTING ADDRESS  : ") ; 
	scanf("%x" , &start_addr) ; 

	FILE *input = fopen("input.txt" , "r") ; 
	char line[100]; 

	fscanf(input,  "%s" , line) ; 
	if(line[0] == 'H'){
		char name[10] ; 
		for(int i = 2 ; i< 8 ; ++i){
			name[i - 2] = line[i] ; 
		}
		printf("FILE NAME IS : %s\n" , name) ; 
	} 
	while(feof(input) == 0){
		fscanf(input , "%s" , line) ; 
		if(line[0] == 'T'){
			char addr[20] ; 
			for(int i = 0 ; i< 4 ; ++i){
				addr[i] = line[i+2] ; 
			}
			int load_addr = strtol(addr , NULL ,16) ; 
			int i = 10 ; 
			while(line[i] != '\0'){
				if(line[i] == '^'){
					i++ ; 
					continue;
				}
				printf("ADDRESS %04X : %c%c\n" , start_addr + load_addr++ , line[i] , line[i+1]) ; 
				i += 2 ; 
			}
		}
		else if(line[0] == 'E'){
			break;
		}
	}
}