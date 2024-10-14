#include <bits/stdc++.h>
using namespace std ; 

int adjacency[100][100] ; 
int nodes ; 
stack<int> st; 
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

void DFS(){
    st.push(0) ;
     while(st.empty() == false){
        int s = st.top()  ; 
        st.pop() ; 
        if( visited[s] == false){
            cout << s << " " ; 
            visited[s] = true ; 
        }
        for( int i = 0 ; i< nodes ; ++i){
            if( adjacency[s][i] > 0 && visited[i] == false){
                st.push(i) ; 
            }
        }
     }
     cout << endl ; 
}

int main(){
    createGraph() ; 
    printGraph() ; 
    DFS() ; 
    return 0 ; 
}