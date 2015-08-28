#include<iostream>
#include<algorithm>

#define MAX 10002

using namespace std ;


int knapsack (int value[] , int wt[] , int n , int maxW);

int knapsack (int value[] , int wt[] , int n , int maxW)
{

	int j , w , knap[maxW+1][n+1] ;
	/*for (i = 0 ; i< n ; i++)
	{
		cout << value[i] << " " << wt[i] << endl ;
	}*/

	for (j = 0 ; j<=n ; j++){
		knap[0][j] = 0 ; 		
	}

	for (j = 0 ; j<=maxW ; j++){
		knap[j][0] = 0 ; 
	}

	for (j = 1 ; j<=n ; j++) {
		for (w = 1 ; w <= maxW ; w++) {
			if (wt[j-1] > w) { // we use j-1 because  the array contains the value from the 0 index
				knap[w][j] = knap[w][j-1]; /* the current weight of the item is greater than the size the knapsack can hold*/
			}

			else {
				knap[w][j] = max (knap[w-wt[j-1]][j-1] +value[j-1] , knap[w][j-1]) ;	 /* either the item j is needed to achieve the max value or it's not needed*/
			}
		}
	}

return knap[maxW][n];
}


int main ()
{
	int v[MAX] , w[MAX] , i , j; // v = value of each item , w = weight of each item 
	int n , maxW ;  //no of bags and the maximum weight the knapsack can hold 
	cout << "Enter the n and Max Weight " ; 
	cin >> n >> maxW ; 
	cout << "Enter the weight and the corresponding value of each item\n" ; 
	for (i = 0 ; i<n ; i++){
		cin >> w[i] >> v[i] ; 
	}
	
	cout << knapsack(v , w , n , maxW) << endl;

return 0 ; 
}
