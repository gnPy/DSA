#include <stdio.h>
#include <string.h>

int palindrome(char *s){
    static int i = 0 ; 
    if(i <= strlen(s)){
        if(*(s+i) != *(s+strlen(s) - i - 1)){
            return 0 ; 
        }
        else{
            i++ ; 
            return palindrome(s) ; 
        }
    }
    return 1 ; 
}
int main(){
    char ch[] = "malayalam"; 
    printf("%d\n", palindrome(ch)); 
}