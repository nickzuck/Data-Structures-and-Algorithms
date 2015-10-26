#include<iostream>
#include<algorithm>
#include<climits>

#define MAX 100

using namespace std ;

int s[MAX][MAX] ;

void print_optimal_parens(int i , int j){
	if (i == j )
		cout << "A" ; 
	else {
		cout << "(" ; 
		print_optimal_parens(i , s[i][j]) ; 
		print_optimal_parens(s[i][j] + 1 , j) ;
		cout << ")" ; 
	}
}

void matrix_chain_order(int p [] , int n ){
	int m[MAX][MAX] ; 
	int i , j , k , l ,q; 
	for (i = 1 ; i<=n ; i++){
		m[i][i] = 0  ; 
	}

	//l = length of chain
	for(l = 2 ; l<=n ;l++){ 
		for(i = 1 ; i<= n-l+1;i++){
			j = i+l-(1) ; //its ei(i) + el(l) - one(1) 
			m[i][j] = INT_MAX ;  //setting m(i,j) = infinity
			for(k = i ; k<= j-1 ;k++){
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				q = min(q , m[i][j]) ; 
				m[i][j] = q ;
				s[i][j] = k;
			}
		}
		
	}
	cout << m[1][n] << endl; 
	print_optimal_parens(1,n) ; 
}

int main()
{
	int p[MAX], i ,n;

	//getting the input
	cout << "Enter the total number of matrices " ; 
	cin >> n; 
	cout << "Enter the dimension array\n" ; 
	for (i= 0 ;i<=n ;i++){
		cin >> p[i] ; 
	} 

	//calculate the matrix-chain-order
	matrix_chain_order(p , n);
return 0 ; 
}