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

int main(){
    int r , c ; 
    printf("ENTER THE ROW AND COLUMN OF MATRICE : ") ; 
    scanf("%d %d" , &r , &c) ;

    int A[r][c] , C[r*c][3]; 

    insertElements(r , c ,A) ; 

    int k1 = convertToThreeTuple(r , c , A , C) ; 

    display(k1 , 3, C) ; 

}