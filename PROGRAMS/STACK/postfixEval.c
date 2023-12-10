#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[100] ; 
int top = -1 ; 

void push(int x){
    stack[++top] = x ; 
}

int pop(){
    return stack[top--] ; 
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

int Precedence(char ch){
    if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    return 0;
}

int operation(int a , int b , char ch){
    if(ch == '+')
        return a + b ; 
    else if(ch == '-')
        return a - b ; 
    else if(ch == '*')
        return a * b ; 
    else if(ch == '/')
        return a / b ; 
}

int postfixEval(char postfix[]){
    int res = 0 ; 
    for( int i = 0 ; i< strlen(postfix) ; i++){
        if(isOperator(postfix[i]) == 0){
            push(postfix[i] - '0') ; 
        }
        else{
            int a = pop() ; 
            int b = pop() ; 
            res = operation(b , a , postfix[i]) ;
            push(res) ;	              
        }
    }
    return res ;
}

int main(){
    char postfix[100] ; 
    printf("ENTER THE EXPRESSION: ") ; 
    scanf("%s" , postfix) ; 
    int res = postfixEval(postfix) ; 
    printf("THE RESULT IS : %d\n" , res) ; 
    return 0 ;
}



