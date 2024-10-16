#include <iostream>
#include <vector>
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

void preorder(struct node* head){
    if(head != NULL){
        cout << head->val << " " ; 
        preorder(head->left) ; 
        preorder(head->right) ; 
    }
}

int main(){
    int n ; 
    vector<int> tree ; 
    cout<< "ENTER THE ARRAY(ENTER '+' TO STOP) : " ;
    while(cin >> n){
        tree.push_back(n) ; 
    }
    struct node* head = arrayToTree(tree) ; 
    preorder(head) ; 
    cout << endl  ;
}