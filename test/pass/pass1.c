#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchSymTab(char label[]){
    FILE *sym ; 
    sym = fopen("symtab.txt" , "r") ;

    char symbol[10] ; 

    int value ; 
    while(feof(sym) == 0){
        fscanf(sym , "%s %d" , symbol , &value) ; 
        if(strcmp(label , symbol) == 0){
            fclose(sym) ; 
            return 1 ; // Label already present
        }
    } 
    fclose(sym) ; 
    return 0 ; // Label not present
}

int searchOpTab(char opcode[]){
    char op[10] ; 
    FILE* optab ; 
    optab = fopen("optab.txt" , "r") ; 

    int value ; 
    while(feof(optab) == 0){
        fscanf(optab , "%s %d" , op , &value) ; 
        if(strcmp(op , opcode) == 0){
            fclose(optab) ; 
            return 1 ; // Match found for LDA
        }
    }
    fclose(optab) ; 
    return 0 ; // No match OF LDA
}

int main(){
    FILE *input , *output , *sym ; 
    
    input = fopen("input.txt" , "r") ; 
    output = fopen("output.txt" , "w") ; 
    sym = fopen("symtab.txt" , "w") ;

    fclose(sym) ; 

    int sA , locctr  , op ; 
    char label[10] , opcode[10] , operand[10] ; 
    
    fscanf(input , "%s %s %d" , label , opcode , &op) ;
    if(strcmp(opcode , "START") == 0){
        locctr = op  ; 
        sA = op ; 
        fprintf(output , "%s %s %d\n" , label , opcode ,op) ; 
    } 
    else{
        locctr = 0 ; 
        sA = 0 ; 
    }

    while(feof(input) == 0){
        fscanf(input , "%s %s %s" , label , opcode , operand) ; 

        if(strcmp(label , "**") == 0){
            if(strcmp(opcode , "END") == 0){
                fprintf(output , "%s %s %s %s\n" , "**" , "END" , "**" , "**") ;
                break ; 
            }
            if(searchOpTab(opcode) == 0){
                printf("Invalid OpCode %s\n" , opcode) ; 
                break ; 
            }
            fprintf(output , "%d %s %s %s\n" , locctr , label , opcode , operand) ; 
            locctr += 3 ; 
        }
        else{
            if(searchSymTab(label) == 1){
                printf("Duplicate Symbol %s\n" , label) ; 
                printf("Error At Location %d\n" , locctr) ; 
                break ; 
            }
            else{
                if(strcmp(opcode , "WORD") == 0){
                    sym = fopen("symtab.txt" , "a") ; 
                    fprintf(output , "%d %s %s %s\n" , locctr , label , opcode , operand) ; 
                    fprintf(sym , "%s %d\n" , label , locctr) ; fclose(sym) ;
                    locctr += 3 ; 
                }
                else if(strcmp(opcode , "BYTE") == 0){
                    sym = fopen("symtab.txt" , "a") ; 
                    fprintf(output , "%d %s %s %s\n" , locctr , label , opcode , operand) ; 
                    fprintf(sym , "%s %d\n" , label , locctr) ; fclose(sym) ;
                    locctr += 1; 
                }
                else if(strcmp(opcode , "RESB") == 0){
                    sym = fopen("symtab.txt" , "a") ; 
                    fprintf(output , "%d %s %s %s\n" , locctr , label , opcode , operand) ; 
                    fprintf(sym , "%s %d\n" , label , locctr) ; fclose(sym) ;
                    locctr += atoi(operand) ; 
                }
                else if(strcmp(opcode , "RESW") == 0){
                    sym = fopen("symtab.txt" , "a") ; 
                    fprintf(output , "%d %s %s %s\n" , locctr , label , opcode , operand) ; 
                    fprintf(sym , "%s %d\n" , label , locctr) ; fclose(sym) ;
                    locctr += 3 * atoi(operand) ; 
                }
                else{
                    printf("INVALID OPCODE %s.\n" , opcode); 
                    break ; 
                }
            }
        }
    }   
    fclose(input) ; 
    fclose(output) ; 

    FILE* length ; 
    length = fopen("length.txt" , "w") ; 
    fprintf(length , "%d" , locctr-sA) ; 
    fclose(length) ; 
	return 0;
}