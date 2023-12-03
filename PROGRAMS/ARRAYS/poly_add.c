#include <stdio.h>

struct term{
	int exp ; 
	int coeff ; 
	};

struct poly{
	int n ; 
	struct term arr[500] ; 
	};

int main(){
	struct poly p1 , p2 , p3;
	p3.n = 0 ;  
	
	printf("ENTER THE NUMBER OF TERMS IN P1 : ") ; 
	scanf("%d" , &p1.n) ;
	for(int i = 0 ;i < p1.n ; i++){
		printf("ENTER THE COEFF AS WELL AS EXP : ") ; 
		scanf("%d %d" , &p1.arr[i].coeff , &p1.arr[i].exp) ; 
		}
	printf("\n") ;

	printf("ENTER THE NUMBER OF TERMS IN P2 :" ) ; 
	scanf("%d" , &p2.n) ; 
 	for( int i = 0 ; i< p2.n ; i++){
		printf("ENTER THE COEFF AS WELL AS EXP : " ) ; 
		scanf("%d %d" , &p2.arr[i].coeff , &p2.arr[i].exp) ; 
		}
	
	printf("\nFIRST  :") ; 
	for( int i = 0 ; i < p1.n ; i++){
		printf("%dx^%d",p1.arr[i].coeff, p1.arr[i].exp) ; 
		i==p1.n-1 ? printf(" ") : printf(" + ") ; 
		}

	printf("\nSECOND :") ; 
	for( int i = 0 ; i < p2.n ; i++){
		printf("%dx^%d",p2.arr[i].coeff, p2.arr[i].exp) ; 
		i==p2.n-1 ? printf(" ") : printf(" + ") ; 
		}

	int i = 0 , j = 0 , k = 0 ; 
	while(i < p1.n && j < p2.n){
		if( p1.arr[i].exp == p2.arr[j].exp){
			p3.arr[k].exp = p1.arr[i].exp ; 
			p3.arr[k++].coeff = p1.arr[i++].coeff+p2.arr[j++].coeff ;
			} 
		else if( p1.arr[i].exp < p2.arr[j].exp){
			p3.arr[k].exp = p1.arr[i].exp ; 
			p3.arr[k++].coeff = p1.arr[i++].coeff ; 
			}
		else{
			p3.arr[k].exp = p2.arr[j].exp ; 
			p3.arr[k++].coeff = p2.arr[j++].coeff ; 
			}
		(p3.n)++ ;
		} 
	for(i = i ; i< p1.n ; i++){
		p3.arr[k].exp = p1.arr[i].exp ; 
		p3.arr[k++].coeff = p1.arr[i].coeff ;
		p3.n++ ;  
		}
	for( j = j ; j < p2.n ; j++){
		p3.arr[k].exp = p2.arr[j].exp ; 
		p3.arr[k++].coeff = p2.arr[j].coeff ;
		p3.n++ ;  
		}
		
	printf("\nSUM :") ; 
	for( int i = 0 ; i < p3.n ; i++){
		printf("%dx^%d",p3.arr[i].coeff , p3.arr[i].exp) ; 
		i == (p3.n)-1 ? printf("\n") : printf(" + ") ; 
		}		
	}

