#include<iostream>
#include<algorithm>
#include<cstring>

//#define MAX 10002

using namespace std ;

int max(int a , int b)
{
	
	return (a > b)? a : b;
}

int calculate (string a , string b , int lena , int lenb)
{
	//cout << a << " " << b ;
	int lcs[lena+1][lenb+1] ;
	int i,j;
        for(i=0;i<=lenb;i++)
            lcs[0][i]=0;
        for(i=0;i<=lena;i++)
            lcs[i][0]=0;
	for (i = 1 ;i<= lena ; i++){
		for (j = 1 ; j<= lenb ; j++){ 
			if (a[i-1] == b[j-1])
			{	lcs[i][j] = lcs[i-1][j-1] + 1 ;
                                cout<<a[i-1]<<endl;
                        }
			else
				lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]) ;
		}
	}
return lcs[lena][lenb] ;
}


int main ()
{
	//char a[MAX], b[MAX] ; 
	int lena , lenb ; 
	string a,b;
	cin >> a ;
	cin >> b;
	
	lena = a.length() ; 
	lenb = b.length() ;
	
	cout << calculate (a , b , lena , lenb) << endl;
return 0 ; 
}
