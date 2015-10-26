#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>

#define MAX 100

using namespace std ;

char first[MAX], second[MAX] ; 
int dp[MAX][MAX] ; 

void printLCS(int , int);

int main ()
{
	int len_first , len_second , i  , j ; 

	//getting the input
	cout << "Enter the first string " ;
	cin >> first ; 
	cout << "Enter the second string " ;
	cin >> second ; 
	

	//storing the length of the strings 
	len_first = strlen(first) ;
 	len_second = strlen(second) ;


	//setting up the dp parameters
	for(i = 1 ; i<=len_first; i++){
		dp[i][0] = 0 ; 
	}

	for(j = 1; j<=len_second ; j++){
		dp[0][j] = 0 ; 
	}


	//making the dp array in bottom up manner
	for(i = 1 ; i<=len_first ;i++){
		for(j = 1 ; j<=len_second ;j++){
			if(first[i-1] == second[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
			}
		}
	}
	cout << "The length of LCS = " << dp[len_first][len_second] ;
	cout << "\nLCS : " ;
	printLCS(len_first , len_second) ;
return 0 ; 
}

void printLCS(int i , int j){
	stack <char> s ; 
	while(i>0 && j>0){
		if (first[i-1] == second[j-1]){
			s.push(first[i-1]);
			i-- ; 
			j-- ;
		}
		else if (dp[i-1][j] > dp[i][j-1])	
			i-- ;
		else 
			j-- ; 

	
	}			
	while(!s.empty()){
		cout << s.top() ; 
		s.pop();
	}
}