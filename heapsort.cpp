/*Using the algorithm from Introduction to Algorithms by Thomas H Cormen */

#include<iostream>
#include<cmath>
#include<algorithm>

#define MAX 100

using namespace std ;

inline void swap(int &a , int &b){
	int temp = b; 
	b = a ; 
	a = temp ;
}

void max_heapify(int *arr , int i , int n ){
	int left , right, largest  ; 
	left = 2*i ; 
	right = left +1 ;
	//largest = i ;
	//for left-subtree
	if(left <= n && arr[left] > arr[i]){
		largest = left ; 
	}
	else {
		largest = i ;
	}
	
	//for right-subtree
	if(right <= n && arr[right]> arr[largest]){
		largest = right ; 
	}

	if (largest != i){
		swap(arr[i] , arr[largest]) ;
	}
	max_heapify(arr , largest , n) ;

}

int main ()
{	
	int arr[MAX] , n ,i;
	cout << "Enter the number of array elements\t";
	cin >> n ; 
	cout << "Enter the elements of the array\n" ;
	for (i=1 ; i<=n ;i++){
		cin >> arr[i] ;
	}

	cout <<"Entered array\n" ;
	for (int i = 1 ; i<= n ; i++){
		cout << arr[i] << "\t" ;
	}
	cout << endl ;

	max_heapify(arr,1,n);

	cout << "after first max_heapify\n" ;
	for (int i = 1 ; i<= n ; i++){
		cout << arr[i] << "\t" ;
	}
return 0 ; 
}