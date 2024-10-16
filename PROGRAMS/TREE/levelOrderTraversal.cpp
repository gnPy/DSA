#include <iostream>
#include <vector>
#include <queue>
using namespace std ; 

struct node{
    int val  ; 
    struct node* left ; 
    struct node* right ; 
    node(int x) : val(x) , left(NULL) , right(NULL){}
} ; 

struct node* arrayToTree(vector<int> tree){
    vector<struct node*> address(tree.size() , NULL) ; 
    for(int i = tree.size() - 1; i >= 0 ; --i){
        if(tree[i] != -1){
            struct node* temp = new node(tree[i]) ; 
            address[i] = temp ; 
            if(2*i + 1 < tree.size()){
                temp->left = address[2*i + 1] ; 
            }
            
            if(2*i + 2 < tree.size()){
                temp->right =address[2 * i + 2] ; 
            }
        }
    }
    return address[0] ; 
}

void LOT(struct node* head){
    queue<struct node*>levels ; 
    levels.push(head) ; 
    while(!levels.empty()){
        struct node* temp = levels.front() ; 
        levels.pop() ; 
        if(temp){
            cout << temp->val  << " " ; ; 
            levels.push(temp->left) ; 
            levels.push(temp->right) ; 
        }
    }
    cout << endl ; 
}

vector<int> printTree(struct node* head){
    vector<int> tree ; 
    queue<struct node*> levels ; 
    levels.push(head) ; tree.push_back(head->val) ; 
    while(levels.empty() == 0){
        struct node* temp = levels.front() ; 
        levels.pop() ; 
        if(temp){
            tree.push_back(temp->left == NULL ? -1 : temp->left->val)   ; 
            tree.push_back(temp->right == NULL ? -1 : temp->right->val) ;

            levels.push(temp->left) ; 
            levels.push(temp->right) ; 
        }
    }
    return tree ; 
}

int main(){
    int n ; 
    vector<int> tree ; 
    cout<< "ENTER THE ARRAY(ENTER '+' TO STOP) : " ;
    while(cin >> n){
        tree.push_back(n) ; 
    }
    struct node* head = arrayToTree(tree) ; 
    LOT(head) ; 
    tree = printTree(head) ; 
    for(int i : tree){
        cout << i << " " ; 
    }
    cout << endl ; 
}

