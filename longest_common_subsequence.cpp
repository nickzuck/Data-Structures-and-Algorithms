#include<iostream>
#include<algorithm>
#include<cstring>

#define MAX 10002

using namespace std ;

int calculate (char a [], char b[] , int lena , int lenb)
{
	//cout << a << " " << b ;
	int lcs[lena+1][lenb+1] ;
	
	for (int i = 0 ;i<= lena ; i++){
		for (int j = 0 ; j<= lenb ; j++){
			cout << a[i] << " " << b[j] << endl;
			if (i == 0 || j == 0)
				lcs[i][j] = 0 ; 
			else if (a[i-1] == b[i-1])
				lcs[i][j] = lcs[i-1][j-1] + 1 ;
			else
				lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]) ;
		}
	}
return lcs[lena][lenb] ;
}

int max(int a , int b)
{
	
	return (a > b)? a : b;
}

int main ()
{
	char a[MAX], b[MAX] ; 
	int lena , lenb ; 
	
	cin >> a ;
	cin >> b;
	
	lena = strlen (a) ; 
	lenb = strlen (b) ;
	
	cout << calculate (a , b , lena , lenb) << endl;
return 0 ; 
}
