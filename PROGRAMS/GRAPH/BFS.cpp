#include <bits/stdc++.h>
using namespace std ; 

int adjacency[100][100] ; 
int nodes ; 
queue<int> q; 
vector<bool> visited(100) ; 

void createGraph(){
    cout << "ENTER NUMBR OF NODES : " ; 
    cin >> nodes ; 
    int a , b ; 
    cout << "ENTER THE CONNECTIONS (TERMINATE USING -1 -1): " << endl ; 
    while( cin >> a >> b && a != -1 && b != -1){
        adjacency[a][b]++ ; 
        adjacency[b][a]++ ; 
    }
}

void printGraph(){
    cout << "CONNECTIONS ARE : " << endl ; 
    for(int i = 0 ; i < nodes ; i++){
        cout << i << " : " ; 
        for(int j = 0 ; j < nodes ; j++){
            if(adjacency[i][j] > 0){
                cout << j << " " ; 
            }
        }
        cout << endl ; 
    }
}

void BFS(){
    visited[0] = true ; 
    q.push(0) ; 
    cout << "The Nodes Are  : "  ; 
    while(!q.empty()){
        int curr = q.front() ; 
        q.pop() ; 
        cout << curr << " " ; 
        for( int i = 0 ; i< nodes ; ++i){
            if(adjacency[curr][i] > 0 && visited[i] == false){
                visited[i] = true ; 
                q.push(i) ; 
            }
        }
    }
    cout << endl ;
}

int main(){
    createGraph() ; 
    printGraph() ; 
    BFS() ; 
    return 0 ; 
}