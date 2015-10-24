#include<iostream>
#include<algorithm>
#include<queue>

#define MAX 1000

using namespace std; 


void radix_sort(int *arr , int n , int digits , int radix = 10) //radix = 10 for decimal numbers
{
	queue <int> radix_queues ; 	
}


//to get the maximum digits present in the given array
int getmaxdigit(int number){
	int count = 0 ; 
	while(number >0){
		number /= 10 ;
		count ++ ;
	}	

return count  ;
}



//driver program
int main ()
{
	int i , n , arr[MAX] , maximum ;
	cout << "Enter the number of elements int the array\t" ; 
	cin>> n;
	cout << "Enter the elements of the array\n";
	maximum = 0 ; 
	for(i = 0 ; i<n ;i++){
		cin >> arr[i];
		maximum = max(maximum , arr[i]) ;
	} 
	int digits = getmaxdigit(maximum);
	cout << digits << endl;
	radix_sort(arr , n, digits );
return 0 ;
}