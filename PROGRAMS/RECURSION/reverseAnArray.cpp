#include <bits/stdc++.h>
using namespace std ; 

void reverse(vector<int> &arr, int i , int j){
    if(i <= j){
        swap(arr[i] , arr[j]) ; 
        reverse(arr , ++i , --j) ; 
    }
}

void print(vector<int> arr){
    for(int i : arr){
        cout << i << " " ; 
    }
    cout << endl ; 
}

int main(){
    vector<int> arr ; 
    int n ;
    cout << " Enter the Array Elements(Press '+' to Stop) : " ;  
    while(cin >> n){
        arr.push_back(n) ; 
    }
    print(arr) ; 
    reverse(arr, 0 , arr.size()- 1) ;
    print(arr) ;     
}