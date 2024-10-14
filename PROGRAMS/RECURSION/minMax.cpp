#include <iostream>
#include <vector>
using namespace std ; 

vector<int> minMax(int i , int j, vector<int> a){
    if( i == j){
        return {a[i] , a[i]} ; 
    }
    else if(i == j - 1){
        return {min(a[i] , a[j]) , max(a[i] , a[j])};
    }
    else{
        auto one = minMax(i , (i+j)/2 , a) ; 
        auto two = minMax((i+j) / 2 , j ,a) ; 
        return {min(one[0] , two[0]) , max(one[1] , two[1])} ; 
    }
}

int main(){
    int n ; 
    cout << "ENTER THE NUMBERS : " ; 
    vector<int> arr ; 
    while(cin >> n){
        arr.push_back(n) ; 
    }
    auto res = minMax(0 , arr.size() - 1 , arr) ; 
    cout << "MINIMUM  : " << res[0] << endl ; 
    cout <<  "MAXIMUM : " << res[1] << endl ; 
    return 0 ; 
}

