#include <stdio.h>

int stack[100] ; 
int top = -1 ; 

void push(int x){
    if( top == 99){
        return ; 
    }
    stack[++top] = x ; 
}

int stackEmpty(){
    return top == -1 ; 
}

int pop(){
    if(stackEmpty()){
        return -1; 
    }
    return stack[top--] ; 
}

void depthFirstTraversal(int graph[][11], int u){
    int visited[11] = {0} ; 
    push(u) ; 
    int current ; 
    while(!stackEmpty()){
        current = pop() ; 
        if(visited[current] == 0){
            printf("%d " , current) ; 
            visited[current]++ ; 
        }
        for(int i = 0 ; i< 11 ; i++){
            if(graph[current][i] == 1 && visited[i] == 0){
                push(i);  
            }
        }
    }
}

int addEdge(int graph[][11] , int u , int v){
    graph[u][v] = 1 ; 
    graph[v][u] =1 ; 
}


int main()
{
    int graph[11][11] = {0};

    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 7);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 10);
    addEdge(graph, 3, 9);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 7, 8);

    printf("\nDepth first traversal from node 1\n");
    depthFirstTraversal(graph, 2);

    printf("\n");
    return 0;
}