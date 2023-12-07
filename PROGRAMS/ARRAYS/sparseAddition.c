#include<stdio.h>

void insertElements(int m , int n , int A[m][n]){
    printf("ENTER THE ELEMENTS  \n") ; 
    for( int i = 0 ; i < m ; i++){
        printf("ENTER THE ROW %d : " , i+1) ; 
        for( int j = 0 ; j < n ; j++){
            scanf("%d" , &A[i][j]) ;
        }
    }
}

void display(int m , int n , int A[m][n]){
    printf("THE SPARSE MATRIX IS : \n") ;
    for( int i = 0 ; i < m ; i++){
        for( int j = 0 ; j < n ; j++){
            printf("%d " , A[i][j]) ; 
        }
        printf("\n") ; 
    }
}

int convertToThreeTuple(int r , int c, int A[r][c] , int C[101][3]){
    int k = 1 ; 

    for( int i = 0 ; i < r ; i++){
        for( int j = 0 ; j < c ; j++){
            if(A[i][j] !=0){
                C[k][0] = i ; 
                C[k][1] = j ; 
                C[k][2] = A[i][j] ; 
                k++ ; 
            }
        }
    }
    C[0][0] = r ; 
    C[0][1] = c ; 
    C[0][2] = k-1 ; 
    return k ; 

}

int addSparseMatrices(int A[][3], int B[][3], int C[][3]) {
    int i = 1, j = 1, k = 1;
    int m = A[0][2], n = B[0][2];

    while(i <= m && j <= n) {
        if(A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
        }
        else if(A[i][0] > B[j][0] || (A[i][0] == B[j][0] && A[i][1] > B[j][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
        }
        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
        }
        k++;
    }

    while(i <= m) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    while(j <= n) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];  
    C[0][2] = k - 1;
    return k;
}





int main(){
    int r , c ; 
    printf("ENTER THE ROW AND COLUMN OF MATRICES : ") ; 
    scanf("%d %d" , &r , &c) ;

    int A[r][c] , B[r][c], C[r*c][3] , D[r*c][3], result[r*c][3]; 

    insertElements(r , c ,A) ; 
    insertElements(r , c ,B) ;

    int k1 = convertToThreeTuple(r , c , A , C) ; 
    int k2 = convertToThreeTuple(r , c , B , D) ;
    int k3 = addSparseMatrices(C, D, result);

    display(k3 , 3, result) ;    

}